## WARNING: The status of the module is "`under construction`"!!!

## Linux Compatibility & Compilation

The code has been tested upon kernels as recent as 5.3

Copy the contents of `security/` into your local Kernel-tree, and run `make menuconfig` to enable the appropriate options.

**NOTE**: Over time the two files `security/Kconfig` & `security/Makefile` might need resyncing with the base versions installed with the Linux source-tree, you can look for mentions of `CAN_EXEC`, `HASH_CHECK`, & `WHITELIST` to see what I've done to add the modules.

For a Debian GNU/Linux host, building a recent kernel, these are the dependencies you'll need to install:

      # apt-get install flex bison bc libelf-dev libssl-dev \
                        build-essential make libncurses5-dev \
                        git-core

