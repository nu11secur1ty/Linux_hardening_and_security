//INCLUDES/////////////////////////////////////////////////////////////////////

#include <linux/init.h>
#include <linux/kd.h>
#include <linux/kernel.h>
#include <linux/tracehook.h>
#include <linux/errno.h>
#include <linux/ext2_fs.h>
#include <linux/sched.h>
#include <linux/security.h>
#include <linux/xattr.h>
#include <linux/capability.h>
#include <linux/unistd.h>
#include <linux/mm.h>
#include <linux/mman.h>
#include <linux/slab.h>
#include <linux/pagemap.h>
#include <linux/proc_fs.h>
#include <linux/swap.h>
#include <linux/spinlock.h>
#include <linux/syscalls.h>
#include <linux/dcache.h>
#include <linux/file.h>
#include <linux/fdtable.h>
#include <linux/namei.h>
#include <linux/mount.h>
#include <linux/netfilter_ipv4.h>
#include <linux/netfilter_ipv6.h>
#include <linux/tty.h>
#include <net/icmp.h>
#include <net/ip.h>		/* for local_port_range[] */
#include <net/tcp.h>		/* struct or_callable used in sock_rcv_skb */
#include <net/net_namespace.h>
#include <net/netlabel.h>
#include <linux/uaccess.h>
#include <asm/ioctls.h>
#include <asm/atomic.h>
#include <linux/bitops.h>
#include <linux/interrupt.h>
#include <linux/netdevice.h>	/* for network interface checks */
#include <linux/netlink.h>
#include <linux/tcp.h>
#include <linux/udp.h>
#include <linux/dccp.h>
#include <linux/quota.h>
#include <linux/un.h>		/* for Unix socket types */
#include <net/af_unix.h>	/* for Unix socket types */
#include <linux/parser.h>
#include <linux/nfs_mount.h>
#include <net/ipv6.h>
#include <linux/hugetlb.h>
#include <linux/personality.h>
#include <linux/audit.h>
#include <linux/string.h>
#include <linux/selinux.h>
#include <linux/mutex.h>
#include <linux/posix-timers.h>
#include <linux/syslog.h>
#include <linux/user_namespace.h>


//DEFINES//////////////////////////////////////////////////////////////////////

#define MODULE_NAME "ptlsm"


//ABOUT////////////////////////////////////////////////////////////////////////

MODULE_AUTHOR("ksajxai");
MODULE_DESCRIPTION("Simple Linux Security Module");
MODULE_LICENSE("GPL");
MODULE_VERSION("0.1.2");


//GLOBALS//////////////////////////////////////////////////////////////////////

extern struct security_operations *security_ops;


//HOOKS/////////////////////////////////////////////////////////////////////////

static int ptlsm_ptrace_access_check(struct task_struct *child,
				     unsigned int mode)
{
	return 0;
}

static int ptlsm_ptrace_traceme(struct task_struct *parent)
{
	return 0;
}

static int ptlsm_capget(struct task_struct *target, kernel_cap_t *effective,
			  kernel_cap_t *inheritable, kernel_cap_t *permitted)
{
	return 0;
}

static int ptlsm_capset(struct cred *new, const struct cred *old,
			  const kernel_cap_t *effective,
			  const kernel_cap_t *inheritable,
			  const kernel_cap_t *permitted)
{
	return 0;
}

static int ptlsm_capable(struct task_struct *tsk, const struct cred *cred,
			   struct user_namespace *ns, int cap, int audit)
{
	return 0;
}

static int ptlsm_quotactl(int cmds, int type, int id, struct super_block *sb)
{
	return 0;
}

static int ptlsm_quota_on(struct dentry *dentry)
{
	return 0;
}

static int ptlsm_syslog(int type)
{
	return 0;
}


static int ptlsm_vm_enough_memory(struct mm_struct *mm, long pages)
{
	return 0;
}

/* binprm security operations */

static int ptlsm_bprm_set_creds(struct linux_binprm *bprm)
{
	return 0;
}

static int ptlsm_bprm_secureexec(struct linux_binprm *bprm)
{
	return 0;
}

static void ptlsm_bprm_committing_creds(struct linux_binprm *bprm)
{
	
}

static void ptlsm_bprm_committed_creds(struct linux_binprm *bprm)
{
	
}

static int ptlsm_sb_alloc_security(struct super_block *sb)
{
	return 0;
}

static void ptlsm_sb_free_security(struct super_block *sb)
{

}

static int ptlsm_sb_copy_data(char *orig, char *copy)
{
	return 0;
}

static int ptlsm_sb_remount(struct super_block *sb, void *data)
{
	return 0;
}

static int ptlsm_sb_kern_mount(struct super_block *sb, int flags, void *data)
{
	return 0;
}

static int ptlsm_sb_statfs(struct dentry *dentry)
{
	return 0;
}

static int ptlsm_mount(char *dev_name, struct path *path, char *type, unsigned long flags, void *data)
{
	return 0;
}

static int ptlsm_umount(struct vfsmount *mnt, int flags)
{
	return 0;
}


/* inode security operations */

static int ptlsm_inode_alloc_security(struct inode *inode)
{
	return 0;
}

static void ptlsm_inode_free_security(struct inode *inode)
{

}

static int ptlsm_inode_init_security(struct inode *inode, struct inode *dir,
				       const struct qstr *qstr, char **name,
				       void **value, size_t *len)
{
	return 0;
}

static int ptlsm_inode_create(struct inode *dir, struct dentry *dentry, int mask)
{
	return 0;
}

static int ptlsm_inode_link(struct dentry *old_dentry, struct inode *dir, struct dentry *new_dentry)
{
	return 0;
}

static int ptlsm_inode_unlink(struct inode *dir, struct dentry *dentry)
{
	return 0;
}

static int ptlsm_inode_symlink(struct inode *dir, struct dentry *dentry, const char *name)
{
	return 0;
}

static int ptlsm_inode_mkdir(struct inode *dir, struct dentry *dentry, int mask)
{
	return 0;
}

static int ptlsm_inode_rmdir(struct inode *dir, struct dentry *dentry)
{
	return 0;
}

static int ptlsm_inode_mknod(struct inode *dir, struct dentry *dentry, int mode, dev_t dev)
{
	return 0;
}

static int ptlsm_inode_rename(struct inode *old_inode, struct dentry *old_dentry,
				struct inode *new_inode, struct dentry *new_dentry)
{
	return 0;
}

static int ptlsm_inode_readlink(struct dentry *dentry)
{
	return 0;
}

static int ptlsm_inode_follow_link(struct dentry *dentry, struct nameidata *nameidata)
{
	return 0;
}

static int ptlsm_inode_permission(struct inode *inode, int mask, unsigned flags)
{
	return 0;
}

static void ptlsm_sb_clone_mnt_opts(const struct super_block *oldsb,
					struct super_block *newsb)
{

}

static int ptlsm_file_set_fowner(struct file *file)
{
	return 0;
}

static int ptlsm_parse_opts_str(char *options, struct security_mnt_opts *opts)
{
    return 0;
}

static int ptlsm_inode_setattr(struct dentry *dentry, struct iattr *iattr)
{
	return 0;
}

static int ptlsm_inode_getattr(struct vfsmount *mnt, struct dentry *dentry)
{
	return 0;
}

static int ptlsm_inode_setotherxattr(struct dentry *dentry, const char *name)
{
	return 0;
}

static int ptlsm_inode_setxattr(struct dentry *dentry, const char *name,
				  const void *value, size_t size, int flags)
{
	return 0;
}

static void ptlsm_inode_post_setxattr(struct dentry *dentry, const char *name,
					const void *value, size_t size,
					int flags)
{
	
}

static int ptlsm_inode_getxattr(struct dentry *dentry, const char *name)
{
	return 0;
}

static int ptlsm_inode_listxattr(struct dentry *dentry)
{
	return 0;
}

static int ptlsm_inode_removexattr(struct dentry *dentry, const char *name)
{
	return 0;
}

static int ptlsm_inode_getsecurity(const struct inode *inode, const char *name, void **buffer, bool alloc)
{
	return 0;
}

static int ptlsm_inode_setsecurity(struct inode *inode, const char *name,
				     const void *value, size_t size, int flags)
{
	return 0;
}

static int ptlsm_inode_listsecurity(struct inode *inode, char *buffer, size_t buffer_size)
{
	return 0;
}

static void ptlsm_inode_getsecid(const struct inode *inode, u32 *secid)
{
	
}


/* file security operations */

static int ptlsm_revalidate_file_permission(struct file *file, int mask)
{
	return 0;
}

static int ptlsm_file_permission(struct file *file, int mask)
{
	return 0;
}

static int ptlsm_file_alloc_security(struct file *file)
{
	return 0;
}

static void ptlsm_file_free_security(struct file *file)
{

}

static int ptlsm_file_ioctl(struct file *file, unsigned int cmd,
			      unsigned long arg)
{
	return 0;
}

static int file_map_prot_check(struct file *file, unsigned long prot, int shared)
{
	return 0;
}

static int ptlsm_file_mmap(struct file *file, unsigned long reqprot,
			     unsigned long prot, unsigned long flags,
			     unsigned long addr, unsigned long addr_only)
{
	return 0;
}

static int ptlsm_file_mprotect(struct vm_area_struct *vma,
				 unsigned long reqprot,
				 unsigned long prot)
{
	return 0;
}

static int ptlsm_file_lock(struct file *file, unsigned int cmd)
{
	return 0;
}

static int ptlsm_file_fcntl(struct file *file, unsigned int cmd,
			      unsigned long arg)
{
	return 0;
}

static int ptlsm_file_send_sigiotask(struct task_struct *tsk,
				       struct fown_struct *fown, int signum)
{
	return 0;
}

static int ptlsm_file_receive(struct file *file)
{
	return 0;
}

static int ptlsm_dentry_open(struct file *file, const struct cred *cred)
{
	return 0;
}


/* task security operations */

static int ptlsm_task_create(unsigned long clone_flags)
{
	return 0;
}

static int ptlsm_cred_alloc_blank(struct cred *cred, gfp_t gfp)
{
	return 0;
}

static void ptlsm_cred_free(struct cred *cred)
{
	
}

static int ptlsm_cred_prepare(struct cred *new, const struct cred *old,
				gfp_t gfp)
{
	return 0;
}

static void ptlsm_cred_transfer(struct cred *new, const struct cred *old)
{

}

static int ptlsm_kernel_act_as(struct cred *new, u32 secid)
{
	return 0;
}

static int ptlsm_kernel_create_files_as(struct cred *new, struct inode *inode)
{
	return 0;
}

static int ptlsm_kernel_module_request(char *kmod_name)
{
	return 0;
}

static int ptlsm_task_setpgid(struct task_struct *p, pid_t pgid)
{
	return 0;
}

static int ptlsm_task_getpgid(struct task_struct *p)
{
	return 0;
}

static int ptlsm_task_getsid(struct task_struct *p)
{
	return 0;
}

static void ptlsm_task_getsecid(struct task_struct *p, u32 *secid)
{
	
}

static int ptlsm_task_setnice(struct task_struct *p, int nice)
{
	return 0;
}

static int ptlsm_task_setioprio(struct task_struct *p, int ioprio)
{
	return 0;
}

static int ptlsm_task_getioprio(struct task_struct *p)
{
	return 0;
}

static int ptlsm_task_setrlimit(struct task_struct *p, unsigned int resource,
		struct rlimit *new_rlim)
{
	return 0;
}

static int ptlsm_task_setscheduler(struct task_struct *p)
{
	return 0;
}

static int ptlsm_task_getscheduler(struct task_struct *p)
{
	return 0;
}

static int ptlsm_task_movememory(struct task_struct *p)
{
	return 0;
}

static int ptlsm_task_kill(struct task_struct *p, struct siginfo *info,
				int sig, u32 secid)
{
	return 0;
}

static int ptlsm_task_wait(struct task_struct *p)
{
	return 0;
}

static void ptlsm_task_to_inode(struct task_struct *p,
				  struct inode *inode)
{

}


/* socket security operations */

static int ptlsm_socket_create(int family, int type,
				 int protocol, int kern)
{
	return 0;
}

static int ptlsm_socket_post_create(struct socket *sock, int family,
				      int type, int protocol, int kern)
{
	return 0;
}

static int ptlsm_socket_bind(struct socket *sock, struct sockaddr *address, int addrlen)
{
	return 0;
}

static int ptlsm_socket_connect(struct socket *sock, struct sockaddr *address, int addrlen)
{
	return 0;
}

static int ptlsm_socket_listen(struct socket *sock, int backlog)
{
	return 0;
}

static int ptlsm_socket_accept(struct socket *sock, struct socket *newsock)
{
	return 0;
}

static int ptlsm_socket_sendmsg(struct socket *sock, struct msghdr *msg,
				  int size)
{
	return 0;
}

static int ptlsm_socket_recvmsg(struct socket *sock, struct msghdr *msg,
				  int size, int flags)
{
	return 0;
}

static int ptlsm_socket_getsockname(struct socket *sock)
{
	return 0;
}

static int ptlsm_socket_getpeername(struct socket *sock)
{
	return 0;
}

static int ptlsm_socket_setsockopt(struct socket *sock, int level, int optname)
{
	return 0;
}

static int ptlsm_socket_getsockopt(struct socket *sock, int level,
				     int optname)
{
	return 0;
}

static int ptlsm_socket_shutdown(struct socket *sock, int how)
{
	return 0;
}

static int ptlsm_socket_unix_stream_connect(struct sock *sock,
					      struct sock *other,
					      struct sock *newsk)
{
	return 0;
}

static int ptlsm_sb_show_options(struct seq_file *m, struct super_block *sb)
{
	return 0;
}

static int ptlsm_set_mnt_opts(struct super_block *sb,
				struct security_mnt_opts *opts)
{
	return 0;
}

static int ptlsm_socket_unix_may_send(struct socket *sock,
					struct socket *other)
{
	return 0;
}

static int ptlsm_sock_rcv_skb_compat(struct sock *sk, struct sk_buff *skb,
				       u16 family)
{
	return 0;
}

static int ptlsm_socket_sock_rcv_skb(struct sock *sk, struct sk_buff *skb)
{
	return 0;
}

static int ptlsm_socket_getpeersec_stream(struct socket *sock, char __user *optval,
					    int __user *optlen, unsigned len)
{
	return 0;
}

static int ptlsm_socket_getpeersec_dgram(struct socket *sock, struct sk_buff *skb, u32 *secid)
{
	return 0;
}

static int ptlsm_sk_alloc_security(struct sock *sk, int family, gfp_t priority)
{
	return 0;
}

static void ptlsm_sk_free_security(struct sock *sk)
{
	
}

static void ptlsm_sk_clone_security(const struct sock *sk, struct sock *newsk)
{
	
}

static void ptlsm_sk_getsecid(struct sock *sk, u32 *secid)
{
	
}

static void ptlsm_sock_graft(struct sock *sk, struct socket *parent)
{
	
}

static int ptlsm_inet_conn_request(struct sock *sk, struct sk_buff *skb,
				     struct request_sock *req)
{
	return 0;
}

static void ptlsm_inet_csk_clone(struct sock *newsk,
				   const struct request_sock *req)
{
	
}

static void ptlsm_inet_conn_established(struct sock *sk, struct sk_buff *skb)
{
	
}

static int ptlsm_secmark_relabel_packet(u32 sid)
{
	return 0;
}

static void ptlsm_secmark_refcount_inc(void)
{

}

static void ptlsm_secmark_refcount_dec(void)
{
	
}

static void ptlsm_req_classify_flow(const struct request_sock *req,
				      struct flowi *fl)
{
	
}

static int ptlsm_tun_dev_create(void)
{
	return 0;
}

static void ptlsm_tun_dev_post_create(struct sock *sk)
{
	
}

static int ptlsm_tun_dev_attach(struct sock *sk)
{
	return 0;
}

static int ptlsm_nlmsg_perm(struct sock *sk, struct sk_buff *skb)
{
	return 0;
}


static int ptlsm_netlink_send(struct sock *sk, struct sk_buff *skb)
{
	return 0;
}

static int ptlsm_netlink_recv(struct sk_buff *skb, int capability)
{
	return 0;
}

static int ipc_alloc_security(struct task_struct *task,
			      struct kern_ipc_perm *perm,
			      u16 sclass)
{
	return 0;
}

static void ipc_free_security(struct kern_ipc_perm *perm)
{
	
}

static int msg_msg_alloc_security(struct msg_msg *msg)
{
	return 0;
}

static void msg_msg_free_security(struct msg_msg *msg)
{
	
}

static int ipc_has_perm(struct kern_ipc_perm *ipc_perms,
			u32 perms)
{
	return 0;
}

static int ptlsm_msg_msg_alloc_security(struct msg_msg *msg)
{
	return 0;
}

static void ptlsm_msg_msg_free_security(struct msg_msg *msg)
{
	
}

static int ptlsm_msg_queue_alloc_security(struct msg_queue *msq)
{
	return 0;
}

static void ptlsm_msg_queue_free_security(struct msg_queue *msq)
{
	
}

static int ptlsm_msg_queue_associate(struct msg_queue *msq, int msqflg)
{
	return 0;
}

static int ptlsm_msg_queue_msgctl(struct msg_queue *msq, int cmd)
{
	return 0;
}

static int ptlsm_msg_queue_msgsnd(struct msg_queue *msq, struct msg_msg *msg, int msqflg)
{
	return 0;
}

static int ptlsm_msg_queue_msgrcv(struct msg_queue *msq, struct msg_msg *msg,
				    struct task_struct *target,
				    long type, int mode)
{
	return 0;
}


/* Shared Memory security operations */

static int ptlsm_shm_alloc_security(struct shmid_kernel *shp)
{
	return 0;
}

static void ptlsm_shm_free_security(struct shmid_kernel *shp)
{
	
}

static int ptlsm_shm_associate(struct shmid_kernel *shp, int shmflg)
{
	return 0;
}

static int ptlsm_shm_shmctl(struct shmid_kernel *shp, int cmd)
{
	return 0;
}

static int ptlsm_shm_shmat(struct shmid_kernel *shp,
			     char __user *shmaddr, int shmflg)
{
	return 0;
}


/* Semaphore security operations */

static int ptlsm_sem_alloc_security(struct sem_array *sma)
{
return 0;
}

static void ptlsm_sem_free_security(struct sem_array *sma)
{

}

static int ptlsm_sem_associate(struct sem_array *sma, int semflg)
{
	return 0;
}

static int ptlsm_sem_semctl(struct sem_array *sma, int cmd)
{
	return 0;
}

static int ptlsm_sem_semop(struct sem_array *sma,
			     struct sembuf *sops, unsigned nsops, int alter)
{
	return 0;
}

static int ptlsm_ipc_permission(struct kern_ipc_perm *ipcp, short flag)
{
	return 0;
}

static void ptlsm_ipc_getsecid(struct kern_ipc_perm *ipcp, u32 *secid)
{

}

static void ptlsm_d_instantiate(struct dentry *dentry, struct inode *inode)
{
	
}

static int ptlsm_getprocattr(struct task_struct *p,
			       char *name, char **value)
{
	return 0;
}

static int ptlsm_setprocattr(struct task_struct *p,
			       char *name, void *value, size_t size)
{
	return 0;
}

static int ptlsm_secid_to_secctx(u32 secid, char **secdata, u32 *seclen)
{
	return 0;
}

static int ptlsm_secctx_to_secid(const char *secdata, u32 seclen, u32 *secid)
{
	return 0;
}

static void ptlsm_release_secctx(char *secdata, u32 seclen)
{
	
}

static int ptlsm_inode_notifysecctx(struct inode *inode, void *ctx, u32 ctxlen)
{
	return 0;
}

static int ptlsm_inode_setsecctx(struct dentry *dentry, void *ctx, u32 ctxlen)
{
	return 0;
}

static int ptlsm_inode_getsecctx(struct inode *inode, void **ctx, u32 *ctxlen)
{
	return 0;
}


//STRUCTS//////////////////////////////////////////////////////////////////////
static struct security_operations ptlsm_ops = {
	.name =				"ptlsm",

	.ptrace_access_check 		=		ptlsm_ptrace_access_check,
	.ptrace_traceme 			=		ptlsm_ptrace_traceme,
	.capget 					=		ptlsm_capget,
	.capset 					=		ptlsm_capset,
	.capable 					=		ptlsm_capable,
	.quotactl 					=		ptlsm_quotactl,
	.quota_on 					=		ptlsm_quota_on,
	.syslog 					=		ptlsm_syslog,
	.vm_enough_memory 			=		ptlsm_vm_enough_memory,

	.netlink_send 				=		ptlsm_netlink_send,
	.netlink_recv 				=		ptlsm_netlink_recv,

	.bprm_set_creds 			=		ptlsm_bprm_set_creds,
	.bprm_committing_creds 		=		ptlsm_bprm_committing_creds,
	.bprm_committed_creds 		=		ptlsm_bprm_committed_creds,
	.bprm_secureexec 			=		ptlsm_bprm_secureexec,

	.sb_alloc_security 			=		ptlsm_sb_alloc_security,
	.sb_free_security 			=		ptlsm_sb_free_security,
	.sb_copy_data 				=		ptlsm_sb_copy_data,
	.sb_remount 				=		ptlsm_sb_remount,
	.sb_kern_mount 				=		ptlsm_sb_kern_mount,
	.sb_show_options 			=		ptlsm_sb_show_options,
	.sb_statfs 					=		ptlsm_sb_statfs,
	.sb_mount 					=		ptlsm_mount,
	.sb_umount			 		=		ptlsm_umount,
	.sb_set_mnt_opts 			=		ptlsm_set_mnt_opts,
	.sb_clone_mnt_opts 			=		ptlsm_sb_clone_mnt_opts,
	.sb_parse_opts_str 			= 		ptlsm_parse_opts_str,

	.inode_alloc_security 		=		ptlsm_inode_alloc_security,
	.inode_free_security 		=		ptlsm_inode_free_security,
	.inode_init_security 		=		ptlsm_inode_init_security,
	.inode_create 				=		ptlsm_inode_create,
	.inode_link 				=		ptlsm_inode_link,
	.inode_unlink 				=		ptlsm_inode_unlink,
	.inode_symlink 				=		ptlsm_inode_symlink,
	.inode_mkdir 				=		ptlsm_inode_mkdir,
	.inode_rmdir 				=		ptlsm_inode_rmdir,
	.inode_mknod 				=		ptlsm_inode_mknod,
	.inode_rename 				=		ptlsm_inode_rename,
	.inode_readlink 			=		ptlsm_inode_readlink,
	.inode_follow_link 			=		ptlsm_inode_follow_link,
	.inode_permission 			=		ptlsm_inode_permission,
	.inode_setattr 				=		ptlsm_inode_setattr,
	.inode_getattr 				=		ptlsm_inode_getattr,
	.inode_setxattr 			=		ptlsm_inode_setxattr,
	.inode_post_setxattr 		=		ptlsm_inode_post_setxattr,
	.inode_getxattr 			=		ptlsm_inode_getxattr,
	.inode_listxattr 			=		ptlsm_inode_listxattr,
	.inode_removexattr 			=		ptlsm_inode_removexattr,
	.inode_getsecurity			=		ptlsm_inode_getsecurity,
	.inode_setsecurity 			=		ptlsm_inode_setsecurity,
	.inode_listsecurity 		=		ptlsm_inode_listsecurity,
	.inode_getsecid 			=		ptlsm_inode_getsecid,

	.file_permission	 		=		ptlsm_file_permission,
	.file_alloc_security 		=		ptlsm_file_alloc_security,
	.file_free_security 		=		ptlsm_file_free_security,
	.file_ioctl 				=		ptlsm_file_ioctl,
	.file_mmap 					=		ptlsm_file_mmap,
	.file_mprotect			 	=		ptlsm_file_mprotect,
	.file_lock 					=		ptlsm_file_lock,
	.file_fcntl 				=		ptlsm_file_fcntl,
	.file_set_fowner 			=		ptlsm_file_set_fowner,
	.file_send_sigiotask 		=		ptlsm_file_send_sigiotask,
	.file_receive 				=		ptlsm_file_receive,
	
	.dentry_open 				=		ptlsm_dentry_open,

	.task_create 				=		ptlsm_task_create,
	.cred_alloc_blank 			=		ptlsm_cred_alloc_blank,
	.cred_free 					=		ptlsm_cred_free,
	.cred_prepare 				=		ptlsm_cred_prepare,
	.cred_transfer 				=		ptlsm_cred_transfer,
	.kernel_act_as 				=		ptlsm_kernel_act_as,
	.kernel_create_files_as 	=		ptlsm_kernel_create_files_as,
	.kernel_module_request 		=		ptlsm_kernel_module_request,
	.task_setpgid 				=		ptlsm_task_setpgid,
	.task_getpgid 				=		ptlsm_task_getpgid,
	.task_getsid 				=		ptlsm_task_getsid,
	.task_getsecid 				=		ptlsm_task_getsecid,
	.task_setnice 				=		ptlsm_task_setnice,
	.task_setioprio 			=		ptlsm_task_setioprio,
	.task_getioprio 			=		ptlsm_task_getioprio,
	.task_setrlimit 			=		ptlsm_task_setrlimit,
	.task_setscheduler 			=		ptlsm_task_setscheduler,
	.task_getscheduler	 		=		ptlsm_task_getscheduler,
	.task_movememory 			=		ptlsm_task_movememory,
	.task_kill 					=		ptlsm_task_kill,
	.task_wait 					=		ptlsm_task_wait,
	.task_to_inode 				=		ptlsm_task_to_inode,

	.ipc_permission 			=		ptlsm_ipc_permission,
	.ipc_getsecid 				=		ptlsm_ipc_getsecid,

	.msg_msg_alloc_security 	=		ptlsm_msg_msg_alloc_security,
	.msg_msg_free_security 		=		ptlsm_msg_msg_free_security,

	.msg_queue_alloc_security 	=		ptlsm_msg_queue_alloc_security,
	.msg_queue_free_security 	=		ptlsm_msg_queue_free_security,
	.msg_queue_associate 		=		ptlsm_msg_queue_associate,
	.msg_queue_msgctl 			=		ptlsm_msg_queue_msgctl,
	.msg_queue_msgsnd 			=		ptlsm_msg_queue_msgsnd,
	.msg_queue_msgrcv 			=		ptlsm_msg_queue_msgrcv,

	.shm_alloc_security 		=		ptlsm_shm_alloc_security,
	.shm_free_security 			=		ptlsm_shm_free_security,
	.shm_associate 				=		ptlsm_shm_associate,
	.shm_shmctl 				=		ptlsm_shm_shmctl,
	.shm_shmat 					=		ptlsm_shm_shmat,

	.sem_alloc_security 		=		ptlsm_sem_alloc_security,
	.sem_free_security 			=		ptlsm_sem_free_security,
	.sem_associate 				=		ptlsm_sem_associate,
	.sem_semctl 				=		ptlsm_sem_semctl,
	.sem_semop 					=		ptlsm_sem_semop,

	.d_instantiate 				=		ptlsm_d_instantiate,

	.getprocattr 				=		ptlsm_getprocattr,
	.setprocattr 				=		ptlsm_setprocattr,

	.secid_to_secctx 			=		ptlsm_secid_to_secctx,
	.secctx_to_secid 			=		ptlsm_secctx_to_secid,
	.release_secctx 			=		ptlsm_release_secctx,
	.inode_notifysecctx 		=		ptlsm_inode_notifysecctx,
	.inode_setsecctx 			=		ptlsm_inode_setsecctx,
	.inode_getsecctx 			=		ptlsm_inode_getsecctx,

	.unix_stream_connect 		=		ptlsm_socket_unix_stream_connect,
	.unix_may_send 				=		ptlsm_socket_unix_may_send,

	.socket_create 				=		ptlsm_socket_create,
	.socket_post_create 		=		ptlsm_socket_post_create,
	.socket_bind 				=		ptlsm_socket_bind,
	.socket_connect 			=		ptlsm_socket_connect,
	.socket_listen 				=		ptlsm_socket_listen,
	.socket_accept 				=		ptlsm_socket_accept,
	.socket_sendmsg 			=		ptlsm_socket_sendmsg,
	.socket_recvmsg 			=		ptlsm_socket_recvmsg,
	.socket_getsockname 		=		ptlsm_socket_getsockname,
	.socket_getpeername		 	=		ptlsm_socket_getpeername,
	.socket_getsockopt 			=		ptlsm_socket_getsockopt,
	.socket_setsockopt 			=		ptlsm_socket_setsockopt,
	.socket_shutdown 			=		ptlsm_socket_shutdown,
	.socket_sock_rcv_skb 		=		ptlsm_socket_sock_rcv_skb,
	.socket_getpeersec_stream 	= 		ptlsm_socket_getpeersec_stream,
	.socket_getpeersec_dgram  	= 		ptlsm_socket_getpeersec_dgram,
	.sk_alloc_security 			= 		ptlsm_sk_alloc_security,
	.sk_free_security 			= 		ptlsm_sk_free_security,
	.sk_clone_security 			= 		ptlsm_sk_clone_security,
	.sk_getsecid 				= 		ptlsm_sk_getsecid,
	.sock_graft 				= 		ptlsm_sock_graft,
	.inet_conn_request 			= 		ptlsm_inet_conn_request,
	.inet_csk_clone 			= 		ptlsm_inet_csk_clone,
	.inet_conn_established		=	  	ptlsm_inet_conn_established,
	.secmark_relabel_packet 	= 		ptlsm_secmark_relabel_packet,
	.secmark_refcount_inc 		= 		ptlsm_secmark_refcount_inc,
	.secmark_refcount_dec 		= 		ptlsm_secmark_refcount_dec,
	.req_classify_flow 			= 		ptlsm_req_classify_flow,
	.tun_dev_create 			= 		ptlsm_tun_dev_create,
	.tun_dev_post_create 		= 		ptlsm_tun_dev_post_create,
	.tun_dev_attach 			= 		ptlsm_tun_dev_attach,
};


//INIT/////////////////////////////////////////////////////////////////////////

static __init int ptlsm_init(void)
{
	if (register_security(&ptlsm_ops)) 
	{
		panic(KERN_INFO "Failed to register ptlsm module\n");
	}
    
    printk(KERN_ALERT "PtLSM started");
	
    return 0;
}


//MACROSES/////////////////////////////////////////////////////////////////////

module_init(ptlsm_init);
