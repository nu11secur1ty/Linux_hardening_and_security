#include <linux/module.h>

/* Defines the license for this LKM */

MODULE_LICENSE("GPL");

/* Init function called on module entry */

int my_module_init( void )

{

  printk(KERN_INFO "my_module_init called.  Module is now loaded.\n");
