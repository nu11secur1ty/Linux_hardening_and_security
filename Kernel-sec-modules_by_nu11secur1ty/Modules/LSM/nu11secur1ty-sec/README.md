## WARNING: The status of the module is "`under construction`"!!!

## Linux Compatibility & Compilation

# OS 
- OpenSuse Leap 15.1

The code has been tested upon kernels as recent as 5.3 it works!


Copy the contents of `security/` into your local Kernel-tree, and run `make menuconfig` to enable the appropriate options.

------------------------------------------------------------------------------------------------------

**NOTE**: This module is created to build file in Kernel virtual directory `proc` with special contend!
          Late I will build another sofware which will pars information from this file and it will never interfere with the kernel.
          From Kernel base, the sitation is the same. The purpose of the module is to provide special data to the user space and    back without breaking the rules!
          
 -------------------------------------------------------------------------------------------------------


For a Debian GNU/Linux host, building a recent kernel, these are the dependencies you'll need to install:

      # apt-get install flex bison bc libelf-dev libssl-dev \
                        build-essential make libncurses5-dev \
                        git-core

![1](https://github.com/nu11secur1ty/Linux_hardening_and_security/blob/master/Kernel-sec-modules_by_nu11secur1ty/Modules/LSM/nu11secur1ty-sec/wall/Screenshot%20from%202019-10-09%2013-39-37.png)

![2](https://github.com/nu11secur1ty/Linux_hardening_and_security/blob/master/Kernel-sec-modules_by_nu11secur1ty/Modules/LSM/nu11secur1ty-sec/wall/Screenshot%20from%202019-10-09%2013-39-47.png)

![3](https://github.com/nu11secur1ty/Linux_hardening_and_security/blob/master/Kernel-sec-modules_by_nu11secur1ty/Modules/LSM/nu11secur1ty-sec/wall/Screenshot%20from%202019-10-09%2013-39-51.png)
