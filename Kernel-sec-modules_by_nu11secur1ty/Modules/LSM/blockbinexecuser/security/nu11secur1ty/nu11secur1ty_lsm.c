/**
 * @file    nu11secur1ty_lsm.c
 * @author  Ventsislav Varbanovski
 * @date    30.09.2019
 * @version 0.1
 * @brief  An introductory "Hello Kernel!" loadable kernel module (LKM) that can display a message
 * in the /var/log/kern.log file when the module is loaded and removed. The module can accept an
 * argument when it is loaded -- the name, which appears in the kernel log files.
 * @see https://www.nu11secur1ty.com/ for a full description and follow-up descriptions.
*/

#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("Dual BSD/GPL");

static int user_init(void)
{
    printk(KERN_ALERT "Hello, user\n");
    return 0;
}

static void user_exit(void)
{
    printk(KERN_ALERT "Goodbye, dear user\n");
}

module_init(user_init);
module_exit(user_exit);
