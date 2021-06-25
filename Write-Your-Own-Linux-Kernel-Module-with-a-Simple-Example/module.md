#What are kernel modules?

Kernel modules are piece of code, that can be loaded and unloaded from kernel on demand.


Kernel modules offers an easy way to extend the functionality of the base kernel without having to rebuild or recompile the kernel again. Most of the drivers are implemented as a Linux kernel modules. When those drivers are not needed, we can unload only that specific driver, which will reduce the kernel image size.
The kernel modules will have a .ko extension. On a normal linux system, the kernel modules will reside inside /lib/modules//kernel/ directory.
This tutorial explains how to write a Kernel module using a simple Hello World example.
I. Utilities to Manipulate Kernel Modules

1. lsmod – List Modules that Loaded Already

lsmod command will list modules that are already loaded in the kernel as shown beblow.
```
 # lsmod  
 Module         Size Used by  
 ppp_deflate      12806 0   
 zlib_deflate      26445 1 ppp_deflate  
 bsd_comp        12785 0   
 ..  
```


2. insmod – Insert Module into Kernel
insmod command will insert a new module into the kernel as shown below.
```
 # insmod /lib/modules/3.5.0-19-generic/kernel/fs/squashfs/squashfs.ko  
 # lsmod | grep "squash"  
 squashfs        35834 0  
```


3. modinfo – Display Module Info
```
modinfo command will display information about a kernel module as shown below.
 # modinfo /lib/modules/3.5.0-19-generic/kernel/fs/squashfs/squashfs.ko  
 filename:    /lib/modules/3.5.0-19-generic/kernel/fs/squashfs/squashfs.ko  
 license:    GPL  
 author:     Phillip Lougher   
 description:  squashfs 4.0, a compressed read-only filesystem  
 srcversion:   89B46A0667BD5F2494C4C72  
 depends:      
 intree:     Y  
 vermagic:    3.5.0-19-generic SMP mod_unload modversions 686  
```

4. rmmod – Remove Module from Kernel
rmmod command will remove a module from the kernel.
You cannot remove a module which is already used by any program.
```
 # rmmod squashfs.ko  
```

5. modprobe – Add or Remove modules from the kernel
modprobe is an intelligent command which will load/unload modules based on the dependency between modules. Refer to modprobe commands for more detailed examples.


II. Write a Simple Hello World Kernel Module


1. Installing the linux headers
You need to install the linux-headers-.. first as shown below. Depending on your distro, use apt-get or yum.
```
 # apt-get install build-essential linux-headers-$(uname -r)  
```

2. Hello World Module Source Code

Next, create the following hello.c module in C programming language.

```
 #include <linux/module.h>  // included for all kernel modules  
 #include <linux/kernel.h>  // included for KERN_INFO  
 #include <linux/init.h>   // included for __init and __exit macros  
 MODULE_LICENSE("GPL");  
 MODULE_AUTHOR("Lakshmanan");  
 MODULE_DESCRIPTION("A Simple Hello World module");  
 static int __init hello_init(void)  
 {  
   printk(KERN_INFO "Hello world!\n");  
   return 0;  // Non-zero return means that the module couldn't be loaded.  
 }  
 static void __exit hello_cleanup(void)  
 {  
   printk(KERN_INFO "Cleaning up module.\n");  
 }  
 module_init(hello_init);  
 module_exit(hello_cleanup);  
```


Warning: All kernel modules will operate on kernel space, a highly privileged mode. So be careful with what you write in a kernel module.

3. Create Makefile to Compile Kernel Module

The following makefile can be used to compile the above basic hello world kernel module.


```
 obj-m += hello.o  
 all:  
   make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules  
 clean:  
   make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean  
```


Use the make command to compile hello world kernel module as shown below.


```
 # make  
 make -C /lib/modules/3.5.0-19-generic/build M=/home/lakshmanan/a modules  
 make[1]: Entering directory `/usr/src/linux-headers-3.5.0-19-generic'  
  CC [M] /home/lakshmanan/a/hello.o  
  Building modules, stage 2.  
  MODPOST 1 modules  
  CC   /home/lakshmanan/a/hello.mod.o  
  LD [M] /home/lakshmanan/a/hello.ko  
 make[1]: Leaving directory `/usr/src/linux-headers-3.5.0-19-generic'  
```


The above will create hello.ko file, which is our sample Kernel module.
4. Insert or Remove the Sample Kernel Module

Now that we have our hello.ko file, we can insert this module to the kernel by using insmod command as shown below.


```
 # insmod hello.ko  
 # dmesg | tail -1  
 [ 8394.731865] Hello world!  
 # rmmod hello.ko  
 # dmesg | tail -1  
 [ 8707.989819] Cleaning up module.  
```


When a module is inserted into the kernel, the module_init macro will be invoked, which will call the function hello_init. Similarly, when the module is removed with rmmod, module_exit macro will be invoked, which will call the hello_exit. Using dmesg command, we can see the output from the sample Kernel module. Please note that printk is a function which is defined in kernel, and it behaves similar to the printf in the IO library. Remember that you cannot use any of the library functions from the kernel module. Now you have learned the basics to create your own Linux Kernel module.
