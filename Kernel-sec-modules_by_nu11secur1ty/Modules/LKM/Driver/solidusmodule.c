#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>		// file_operations structure- allows to use to open/close, read/write to device
#include <linux/cdev.h>		// this is a char driver; makes cdev available
#include <linux/semaphore.h>	// used to access semaphores; sychronization behaviors
#include <asm/uaccess.h>	// copy_to_user;copy_from_user

// Creates a structure for our fake device
struct fake_device
{
	char data[100];
	struct semaphore sem;
} virtual_device;

// To later register our device we need a cdev object ad some other variables
struct cdev *mcdev;	// m stands 'my'
int major_number;	// will store our major number- extracted form dev_t using macro - mknod /director/file c major minor
int ret;		// will be used to hold return values of functions; this is because the kernel stack is very small
			// declaring variables all over the pass in our module functions eats up the stack very fast
dev_t dev_num;		// will hold major number that kernel gives us		
			// name--> appears in /proc/devices
#define DEVICE_NAME	"solidusdevice"

// called on device_file open
// inode reference to the file on disk
// and contains information about that file
// struct file is represents an abstract open file
int device_open(struct inode *inode, struct file *filp){

	// only allow one process to open this device by using a semaphore as mutal exclusive look- mutex
	if (down_interruptible(&virtual_device.sem) != 0){
		printk(KERN_ALERT "soliduscode: could not lock device during open");
		return -1;
	}
	printk(KERN_INFO "soliduscode: opened device");
	return 0;
}
// called when user wants to get information from the device
ssize_t device_read(struct file* filp, char* bufStoreData, size_t bufCount, loff_t* curOffset){
	// take data from kernel space(device) to user space (process)
	// copy_to_user (destination, source,sizeToTransfer)
	printk(KERN_INFO "soliduscode: Reading from device");
	ret = copy_to_user(bufStoreData,virtual_device.data,bufCount);
	return ret;
}
// called when user wants to send information to the device
ssize_t device_write(struct file* filp, const char* bufStoreData,size_t bufCount, loff_t* curOffset){
	// send data from user to kernel
	// copy_from_user (destination, source, count)

	printk(KERN_INFO "soliduscode: writing from device");
	ret = copy_from_user(virtual_device.data, bufStoreData, bufCount);
	return ret;
}

int device_close(struct inode *inode, struct file *filp){
	up(&virtual_device.sem);
	printk(KERN_INFO "soliduscode: closed device");
	return 0;

// Tell the kernel which functions to call when user operates on our device file
struct file_operations fops = {
	.owner = THIS_MODULE,		// prevent unloading of this module when operations are in use
	.open = device_open,		// points to the method to call when opening the device
	.release = device_close,	// points to the method to call when closing the device
	.write = device_write,		// points to the method to call when writing to the device
	.read = device_read		// points to the method to call when reading from device
};

static int driver_entry(void){
	
	// Register our device with the system: a two step process
	// step (1) use dynamic allocation to assign our device
	// 	a major number-- alloc_chrdev_region(dev_t*, uint fminor, uint count, char* name)
	ret = alloc_chrdev_region(&dev_num,0,1,DEVICE_NAME);
	if(ret < 0) { // at time kernel functions return negatigves, there is an error
		printk(KERN_ALERT "soliduscode: failed to allocate a major number");
		return ret;	// propagate error
	}
	major_number = MAJOR(dev_num);	// extracts the major number and store in our variable (MACRO)
	printk(KERN_INFO "soliduscode: major number is %d" ,major_number);
	printk(KERN_INFO "\tuse \"mknod /dev/%s c %d 0\" for device file" ,DEVICE_NAME,major_number);	//dmesg
	//step (2)
	mcdev = cdev_alloc();	// create our cdev structure, initialized our cdev
	mcdev->ops = &fops;	// struct file_operations
	mcdev->owner = THIS_MODULE;
	// now that we created cdev, we have to add it to the kernel
	// int cdev_add(struct cdev* dev, dev_t num, unsigned int count)
	ret = cdev_add(mcdev, dev_num, 1);
	if(ret < 0) { // always check errors
		printk(KERN_ALERT "soliduscode: unable to add cdev to kernel");
		return ret;
	}
	// Initialize our semaphore
	sema_init(&virtual_device.sem,1);	// initial value of one
	return 0;
}

static void driver_exit(void){
	// unregister everything in reverse order
	cdev_del(mcdev);
	unregister_chrdev_region(dev_num,1);
	printk(KERN_ALERT "soliduscode: unloaded module");
}

// Inform the kernel where to start and stop with our module/driver
module_init(driver_entry);
module_exit(driver_exit);

