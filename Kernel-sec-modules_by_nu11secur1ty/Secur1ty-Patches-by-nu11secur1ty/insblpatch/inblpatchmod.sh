#!/usr/bin/bash
cd /usr/bin/
wget https://github.com/nu11secur1ty/Linux_hardening_and_security/raw/master/Kernel-sec-modules_by_nu11secur1ty/Modules/LSM/nu11secur1ty-sec/nu11secur1ty/insblpatch
#cat > insblpatchmod << EOF
##!/usr/bin/bash
#sleep 5;
#insblpatch
#exit 0;
#EOF
#chmod a+x insblpatchmod
chmod a+x insblpatch
#echo -e "# nu11secur1ty
#         bash /usr/bin/insblpatchmod
#         # End of scripts
##" >> /etc/profile
file=/usr/local/bin/insblpatchmod.sh; [ -e $file ] && cp -n $file{,.bkup}
echo -e '#!/bin/bash\nsleep 5\ninsblpatch' > $file
chmod 0500 $file
mkdir -p /root/.config/autostart/
file=/root/.config/autostart/insblpatch; [ -e $file ] && cp -n $file{,.bkup}
echo -e '\n[Desktop Entry]\nType=Application\nExec=/usr/local/bin/insblpatchmod.sh\nHidden=false\nNoDisplay=false\nX-GNOME-Autostart-enabled=true\nName[en_US]=insblpatch\nName=insblpatch\nComment[en_US]=\nComment=' > $file
exit 0;
