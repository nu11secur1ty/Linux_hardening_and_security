# Installing the test Hello Kernel module on OpenSuse-leap 15
- Get the source:
----------------------------------------------------------------------------------------------------------
1. - The Makefile
```bash 
wget https://raw.githubusercontent.com/nu11secur1ty/Linux_hardening_and_security/master/Kernel-sec-modules_by_nu11secur1ty/Modules/LKM/Hello-Kernel/Makefile
```
2. - the module
```bash
wget https://raw.githubusercontent.com/nu11secur1ty/Linux_hardening_and_security/master/Kernel-sec-modules_by_nu11secur1ty/Modules/LKM/Hello-Kernel/hello.c
```
3. - The Headers, if you needet
```bash
wget https://github.com/nu11secur1ty/Linux_hardening_and_security/raw/master/Kernel-sec-modules_by_nu11secur1ty/Modules/LKM/Hello-Kernel/kernel-headers-5.0.9-300.fc30.x86_64.rpm
```
----------------------------------------------------------------------------------------------------------
- Installing
  - - packages which you need from Yast
```bash
Base Development                                          
C/C++ Development                                                                                    
RPM Build Environment                                                                    
Linux Kernel Development 
```
- applay

```bash
cd /path/to/your/module/
make
insmod hello.ko
```
