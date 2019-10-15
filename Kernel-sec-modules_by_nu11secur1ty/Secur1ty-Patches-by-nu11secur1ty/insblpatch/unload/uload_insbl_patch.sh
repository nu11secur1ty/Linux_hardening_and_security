#!/usr/bin/bash
systemctl stop insbl_mod_patch.service
cd /etc/systemd/system
  rm *insbl_mod_patch.service*
  sleep 3;
cd /usr/bin
    rm -rf *insblpatch* 
    rm -rf *insblpatchmod*
 echo "Now you must reboot the system to unload completely the insmod_block module"
exit 0;
