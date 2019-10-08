#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <linux/string.h>
#include <linux/vmalloc.h>
#include <asm/uaccess.h>

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Fortune Cookie Kernel Module");
MODULE_AUTHOR("M. Tim Jones");

#define MAX_COOKIE_LENGTH       PAGE_SIZE
static struct proc_dir_entry *proc_entry;
static char *cookie_pot;  // Space for fortune strings
static int cookie_index;  // Index to write next fortune
static int next_fortune;  // Index to read next fortune

int init_fortune_module( void )

{

  int ret = 0;
  cookie_pot = (char *)vmalloc( MAX_COOKIE_LENGTH );

  if (!cookie_pot) {
    ret = -ENOMEM;
  } else {
    
    memset( cookie_pot, 0, MAX_COOKIE_LENGTH );
    proc_entry = create_proc_entry( "fortune", 0644, NULL );

    if (proc_entry == NULL) {

      ret = -ENOMEM;

      vfree(cookie_pot);

      printk(KERN_INFO "fortune: Couldn't create proc entry\n");

    } else {

      cookie_index = 0;

      next_fortune = 0;

      proc_entry->read_proc = fortune_read;

      proc_entry->write_proc = fortune_write;

      proc_entry->owner = THIS_MODULE;

      printk(KERN_INFO "fortune: Module loaded.\n");

    }

  }

  return ret;

}

void cleanup_fortune_module( void )

{

  remove_proc_entry("fortune", &proc_root);

  vfree(cookie_pot);

  printk(KERN_INFO "fortune: Module unloaded.\n");

}

module_init( init_fortune_module );

module_exit( cleanup_fortune_module );
