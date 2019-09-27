/*
 * nu11secur1ty_lsm.c
 *
 * Allow/deny execution of programs to non-root users, by looking for
 * a security attribute upon the file.
 *
 * To set a program as nu11secur1tyted you must add a label to the target,
 * for example:
 *
 *     setfattr -n security.nu11secur1ty -v 3 /bin/dash
 *
 * To confirm there is a label present you can use the dump option:
 *
 *     ~# getfattr -d -m security /bin/dash
 *     getfattr: Removing leading '/' from absolute path names
 *     # file: bin/dash
 *     security.nu11secur1ty="3"
 *
 * Finally to revoke the label, and deny execution once more:
 *
 *     ~# setfattr -x security.nu11secur1ty /bin/dash
 *
 * There is a helper tool located in `samples/nu11secur1ty` which wraps
 * that for you, in a simple way.
 *
 * Steve
 * --
 *
 */


#include <linux/xattr.h>
#include <linux/binfmts.h>
#include <linux/lsm_hooks.h>
#include <linux/cred.h>


/*
 * Perform a check of a program execution/map.
 *
 * Return 0 if it should be allowed, -EPERM on block.
 */
static int nu11secur1ty_bprm_check_security(struct linux_binprm *bprm)
{
       // The current task & the UID it is running as.
       const struct task_struct *task = current;
       kuid_t uid = task->cred->uid;

       // The target we're checking
       struct dentry *dentry = bprm->file->f_path.dentry;
       struct inode *inode = d_backing_inode(dentry);

       // Size of the attribute, if any.
       int size = 0;

       // Root can access everything.
       if ( uid.val == 0 )
          return 0;

       // Is there an attribute?  If so allow the access
       size = __vfs_getxattr(dentry, inode, "security.nu11secur1ty", NULL, 0);
       if ( size > 0 )
           return 0;

       // Otherwise deny it.
       printk(KERN_INFO "nu11secur1ty LSM check of %s denying access for UID %d [ERRO:%d] \n", bprm->filename, uid.val, size );
       return -EPERM;
}

/*
 * The hooks we wish to be installed.
 */
static struct security_hook_list nu11secur1ty_hooks[] __lsm_ro_after_init = {
	LSM_HOOK_INIT(bprm_check_security, nu11secur1ty_bprm_check_security),
};

/*
 * Initialize our module.
 */
void __init nu11secur1ty_add_hooks(void)
{
	security_add_hooks(nu11secur1ty_hooks, ARRAY_SIZE(nu11secur1ty_hooks), "nu11secur1ty");
	printk(KERN_INFO "nu11secur1ty LSM initialized\n");
}
