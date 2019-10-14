#!/usr/bin/bash
cd /root/
wget https://github.com/nu11secur1ty/Linux_hardening_and_security/raw/master/Kernel-sec-modules_by_nu11secur1ty/Secur1ty-Patches-by-nu11secur1ty/insblpatch/unload/insmod_unload
./insmod_unload
sleep 3;
  rm -rf insmod_unload
  
