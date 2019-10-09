## WARNING: The status of the module is "`under construction`"!!!

## Linux Compatibility & Compilation
-----------------------------------------------------------------------------------------------------

Copy the contents of `security/` into your local Kernel-tree, and run `make menuconfig` to enable the appropriate options.

# The correct way to install:
```
[*] NU11SECUR1TY Linux Support NEW ;)
    (2048) Default maximal count for learning mode NEW ;)
    (1024) Default maximal count for audit log NEW ;)
[*] Activate without calling userspace policy loader. NEW ;)
```
------------------------------------------------------------------------------------------------------

# Tested on Kernels:
- 5.3.4 it works!
- OS's 
- OpenSuse Leap 15.1
------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------
**NOTE**: This module is created to build files in Kernel virtual directory `proc` with special content! Later I will build another software that will pars information from this file and it will never interfere with the kernel. From the Kernel base, the situation is the same. The purpose of the module is to provide special data to the user space, and back without breaking the rules! The module is especially for blocking the kernel `insmod` tool!
          
 -------------------------------------------------------------------------------------------------------


For a Debian GNU/Linux host, building a recent kernel, these are the dependencies you'll need to install:

```bash
  apt-get install flex bison bc libelf-dev libssl-dev \
  build-essential make libncurses5-dev \
  git-core
```

![1](https://github.com/nu11secur1ty/Linux_hardening_and_security/blob/master/Kernel-sec-modules_by_nu11secur1ty/Modules/LSM/nu11secur1ty-sec/wall/Screenshot%20from%202019-10-09%2013-39-37.png)

![2](https://github.com/nu11secur1ty/Linux_hardening_and_security/blob/master/Kernel-sec-modules_by_nu11secur1ty/Modules/LSM/nu11secur1ty-sec/wall/Screenshot%20from%202019-10-09%2013-39-47.png)

![3](https://github.com/nu11secur1ty/Linux_hardening_and_security/blob/master/Kernel-sec-modules_by_nu11secur1ty/Modules/LSM/nu11secur1ty-sec/wall/Screenshot%20from%202019-10-09%2013-39-51.png)

![4](https://github.com/nu11secur1ty/Linux_hardening_and_security/blob/master/Kernel-sec-modules_by_nu11secur1ty/Modules/LSM/nu11secur1ty-sec/wall/Screenshot%20from%202019-10-09%2015-12-51.png)
