# Sec-changes by nu11secur1ty:
- This is a "modules_disabled" function security change and by default, you can not load any costume LKM module on this Linux Kernel


- module
```bash
https://github.com/nu11secur1ty/Linux_hardening_and_security/blob/master/Kernel-sec-modules_by_nu11secur1ty/linux-5.3.2/kernel/module.c#L971
```
- sysctl
```bash
https://github.com/nu11secur1ty/Linux_hardening_and_security/blob/master/Kernel-sec-modules_by_nu11secur1ty/linux-5.3.2/kernel/sysctl.c#L714
```
