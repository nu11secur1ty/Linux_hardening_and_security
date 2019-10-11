Suppose you want to install the kernel header file to /usr/src/linux-headers-4.15.3. The compiled kernel source tree is located /path/to/compiled/linux-4.15.3/

first, unpack a clean kernel source tree

tar xvf linux-4.15.3.tar.xz
cd linux-4.15.3/

second, copy you .config file to the directory

cp /path/to/compiled/linux-4.15.3/.config .

third, run it and then delete .config file in source directory to get a clean kernel source

make O=/usr/src/linux-headers-4.15.3 oldconfig
rm .config

fourth, run the modules_prepare make target

make O=/usr/src/linux-headers-4.15.3 modules_prepare

Finally, delete useless things, and copy the necessary things

rm /usr/src/linux-headers-4.15.3/source
cp /path/to/compiled/linux-4.15.3/Module.symvers /usr/src/linux-headers-4.15.3

Now, the /usr/src/linux-headers-4.15.3 directory is able to build the module.

Documentation https://www.kernel.org/doc/Documentation/kbuild/modules.txt tell us modules_prepare

    This will make sure the kernel contains the information required. The target exists solely as a simple way to prepare a kernel source tree for building external modules.

    NOTE: "modules_prepare" will not build Module.symvers even if CONFIG_MODVERSIONS is set; therefore, a full kernel build needs to be executed to make module versioning work.
