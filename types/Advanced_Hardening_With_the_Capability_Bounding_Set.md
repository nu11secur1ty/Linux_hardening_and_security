# Advanced Hardening With the Capability Bounding Set on old versions of Linux
![](https://github.com/nu11secur1ty/Linux_hardening_and_security/blob/master/photo/security.jpg)

# How to See Default or Current Capability Values?

-----------------------------------------------------------------------------------------------------
- NOTE:
# SUSE - cat /proc/sys/kernel/cap_last_cap =) !-permissions ("chattr") newest Linux_ARC system_D {so beautifully =)}!
# For others OS you have to check!
```
$ cat /proc/sys/kernel/cap-bound
$ cat /proc/sys/kernel/cap_last_cap  # on SUSE
```
# How to Set New Capability Values?


```
echo 0xHexValue > /proc/sys/kernel/cap-bound
```
# Stop Loading Modules (Drivers) After System Has Booted

```
echo 0xFFFEFFFF > /proc/sys/kernel/cap-bound
```

# Test

```
modprobe ide_cd
```
# Sample outputs:

```
FATAL: Error inserting ide_cd (/lib/modules/2.6.18-194.3.1.el5/kernel/drivers/ide/ide-cd.ko): Operation not permitted
```
# OR try to remove module:

```
modprobe -r cdrom
```

# Sample outputs:


```
FATAL: Error removing cdrom (/lib/modules/2.6.18-194.3.1.el5/kernel/drivers/cdrom/cdrom.ko): Operation not permitted
```

# How to Make Changes To Capability Permanently?

```
 vim /etc/sysctl.conf

```

# Append the following line:

```
# Do not load or remove any kernel drivers
# Clear bit # 16
echo 0xFFFEFFFF > /proc/sys/kernel/cap-bound
```


# Save and close the file. Load changes:

```
sysctl -p
```

# How to Find Out List Of All Supported Capabilities?

To get an overview of Linux capabilities and its numbers see /usr/src/linux/include/linux/capability.h file, enter:

```
$ vi /usr/src/linux/include/linux/capability.h
```

# OR use the grep command to find out numbers quickly:

```
grep '#define CAP' /usr/src/linux/include/linux/capability.h
```

# Sample outputs:


```
#define CAP_CHOWN            0
#define CAP_DAC_OVERRIDE     1
#define CAP_DAC_READ_SEARCH  2
#define CAP_FOWNER           3
#define CAP_FSETID           4
#define CAP_KILL             5
#define CAP_SETGID           6
#define CAP_SETUID           7
#define CAP_SETPCAP          8
#define CAP_LINUX_IMMUTABLE  9
#define CAP_NET_BIND_SERVICE 10
#define CAP_NET_BROADCAST    11
#define CAP_NET_ADMIN        12
#define CAP_NET_RAW          13
#define CAP_IPC_LOCK         14
#define CAP_IPC_OWNER        15
#define CAP_SYS_MODULE       16
#define CAP_SYS_RAWIO        17
#define CAP_SYS_CHROOT       18
#define CAP_SYS_PTRACE       19
#define CAP_SYS_PACCT        20
#define CAP_SYS_ADMIN        21
#define CAP_SYS_BOOT         22
#define CAP_SYS_NICE         23
#define CAP_SYS_RESOURCE     24
#define CAP_SYS_TIME         25
#define CAP_SYS_TTY_CONFIG   26
#define CAP_MKNOD            27
#define CAP_LEASE            28
#define CAP_AUDIT_WRITE      29
#define CAP_AUDIT_CONTROL    30
#define CAP_SETFCAP	     31
#define CAP_MAC_OVERRIDE     32
#define CAP_MAC_ADMIN        33
#define CAP_LAST_CAP         CAP_MAC_ADMIN
#define CAP_TO_INDEX(x)     ((x) >> 5)        /* 1 << 5 == bits in __u32 */
#define CAP_TO_MASK(x)      (1 << ((x) & 31)) /* mask for indexed __u32 */
#define CAP_FOR_EACH_U32(__capi)  \
#define CAP_INIT_INH_SET    CAP_EMPTY_SET
#define CAP_BOP_ALL(c, a, b, OP)                                    \
#define CAP_UOP_ALL(c, a, OP)                                       \

```



# The capabilities man page also offers good overview of Linux capabilities:

```
$ man 7 capabilities
```

# Have fun with nu11secur1ty.























































