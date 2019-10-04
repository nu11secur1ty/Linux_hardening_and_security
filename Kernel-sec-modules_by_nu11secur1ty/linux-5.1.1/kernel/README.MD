# in progress...
# Sec-changes by nu11secur1ty:
- This is a "modules_disabled" function security change and by default, you can not load any costume LKM module on this Linux Kernel. This security change on this Kernel is for special PRO servers which contain very sensitive information and others
servers similar to these!
BR `nu11secur1ty`
-------------------------------------------------------------------------------------------------------------------------
- module
```bash
https://github.com/nu11secur1ty/Linux_hardening_and_security/blob/master/Kernel-sec-modules_by_nu11secur1ty/linux-5.1.1/kernel/module.c#L290
```
- sysctl
```bash
https://github.com/nu11secur1ty/Linux_hardening_and_security/blob/master/Kernel-sec-modules_by_nu11secur1ty/linux-5.1.1/kernel/sysctl.c#L705
```
