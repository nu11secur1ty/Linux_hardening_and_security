# Test on CentOS Linux.

------------------------------------------------------------------
# Install packages:
```
   zypper in gcc
   zypper in make 
   zypper in ncurses-devel
```
# Commands: 
```
   make mrproper
   make menuconfig
```   
   [*] Enable loadable module support  --->  
   
     ───────────── Enable loadable module support ────────
  │ CONFIG_MODULES:                                                                                                                                                                                              
  │                                                                                                                                                                                                              
  │ Kernel modules are small pieces of compiled code which can                                                                                                                                                   
  │ be inserted in the running kernel, rather than being                                                                                                                                                         
  │ permanently built into the kernel.  You use the "modprobe"                                                                                                                                                   
  │ tool to add (and sometimes remove) them.  If you say Y here,                                                                                                                                                 
  │ many parts of the kernel can be built as modules (by                                                                                                                                                         
  │ answering M instead of Y where indicated): this is most                                                                                                                                                      
  │ useful for infrequently used options which are not required                                                                                                                                                  
  │ for booting.  For more information, see the man pages for                                                                                                                                                    
  │ modprobe, lsmod, modinfo, insmod and rmmod.                                                                                                                                                                  
  │                                                                                                                                                                                                              
  │ If you say Y here, you will need to run "make                                                                                                                                                                
  │ modules_install" to put the modules under /lib/modules/                                                                                                                                                      
  │ where modprobe can find them (you may need to be root to do                                                                                                                                                  
  │ this).                                                                                                                                                                                                       
  │                                                                                                                                                                                                              
  │ If unsure, say Y.                                                                                                                                                                                            
  │                                                                                                                                                                                                              
  │ Symbol: MODULES [=y]                                                                                                                                                                                         
  │ Type  : boolean                                                                                                                                                                                              
  │ Prompt: Enable loadable module support                                                                                                                                                                       
  │   Defined at init/Kconfig:1950    
 
 # Configure your kernel =)
 
   save and exit:  
```

    make bzImage
    make modules
    make modules_install
```
  - WARNING NOTE:   

   # Stop loadable module support.
   [ ] Enable loadable module support  ----  


  ┌───────────── Enable loadable module support ──────
  │ CONFIG_MODULES:                                                                                                                                                                                              
  │                                                                                                                                                                                                              
  │ Kernel modules are small pieces of compiled code which can                                                                                                                                                   
  │ be inserted in the running kernel, rather than being                                                                                                                                                         
  │ permanently built into the kernel.  You use the "modprobe"                                                                                                                                                   
  │ tool to add (and sometimes remove) them.  If you say Y here,                                                                                                                                                 
  │ many parts of the kernel can be built as modules (by                                                                                                                                                         
  │ answering M instead of Y where indicated): this is most                                                                                                                                                      
  │ useful for infrequently used options which are not required                                                                                                                                                  
  │ for booting.  For more information, see the man pages for                                                                                                                                                    
  │ modprobe, lsmod, modinfo, insmod and rmmod.                                                                                                                                                                  
  │                                                                                                                                                                                                              
  │ If you say Y here, you will need to run "make                                                                                                                                                                
  │ modules_install" to put the modules under /lib/modules/                                                                                                                                                      
  │ where modprobe can find them (you may need to be root to do                                                                                                                                                  
  │ this).                                                                                                                                                                                                       
  │                                                                                                                                                                                                              
  │ If unsure, say Y.                                                                                                                                                                                            
  │                                                                                                                                                                                                              
  │ Symbol: MODULES [=n]                                                                                                                                                                                         
  │ Type  : boolean                                                                                                                                                                                              
  │ Prompt: Enable loadable module support                                                                                                                                                                       
  │   Defined at init/Kconfig:1950 
```
    make install
```
  # Feel secure with nu11secur1ty.



