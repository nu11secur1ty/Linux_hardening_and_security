nu11secur1ty
---------

This is a LSM in which the kernel denies the execution of binaries
to non-root users, unless there is an extended-attribute named
`security.nu11secur1ty` present upon the binary.

**NOTE**: The content/value of that attribute doesn't matter, only
the existance is tested

There is some back-story in the following blog-post:

* https://blog.steve.fi/so_i_accidentally_wrote_a_linux_security_module.html

Continuing the development: 

* https://github.com/nu11secur1ty/Linux_hardening_and_security/tree/master/Kernel-sec-modules_by_nu11secur1ty
