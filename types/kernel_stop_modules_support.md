1. Install packages:
   zypper in gcc
   zypper in make 
   zypper in ncurses-devel

# Commands: 
   make mrproper
   make menuconfig
   in  [*] Enable loadable module support  --->   
 
  save and exit:  
  - help for Module unloading:
       //CONFIG_MODULE_UNLOAD:                                                                                                                                                                                       
  │                                                                                                                                                                                                             
  │ Without this option you will not be able to unload any                                                                                                                                                      
  │ modules (note that some modules may not be unloadable                                                                                                                                                       
  │ anyway), which makes your kernel smaller, faster                                                                                                                                                            
  │ and simpler.  If unsure, say Y.                                                                                                                                                                             
  │                                                                                                                                                                                                             
  │ Symbol: MODULE_UNLOAD [=y]                                                                                                                                                                                  
  │ Type  : boolean                                                                                                                                                                                             
  │ Prompt: Module unloading                                                                                                                                                                                    
  │   Location:                                                                                                                                                                                                 
  │     -> Enable loadable module support (MODULES [=y])                                                                                                                                                        
  │   Defined at init/Kconfig:1928                                                                                                                                                                              
  │   Depends on: MODULES [=y]                                                                                                                                                                                 
  │                            
   - 

   # Stop loading modules.
   [ ]   Forced module loading 

    ┌───────────────── Forced module loading ────────
  │ CONFIG_MODULE_FORCE_LOAD:                                                                                                                                                                                    
  │                                                                                                                                                                                                              
  │ Allow loading of modules without version information (ie. modprobe                                                                                                                                           
  │ --force).  Forced module loading sets the 'F' (forced) taint flag and                                                                                                                                        
  │ is usually a really bad idea.                                                                                                                                                                                
  │                                                                                                                                                                                                              
  │ Symbol: MODULE_FORCE_LOAD [=n]                                                                                                                                                                               
  │ Type  : boolean                                                                                                                                                                                              
  │ Prompt: Forced module loading                                                                                                                                                                                
  │   Location:                                                                                                                                                                                                  
  │     -> Enable loadable module support (MODULES [=y])                                                                                                                                                         
  │   Defined at init/Kconfig:1920                                                                                                                                                                               
  │   Depends on: MODULES [=y]   



    make bzImage
#   make modules
#   make modules_install
    make
    make install

2. After test:
grub2-mkconfig -o /boot/grub2/grub.cfg



