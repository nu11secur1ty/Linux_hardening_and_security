#!/usr/bin/bash
# Author V.Varbanovski @nu11secur1ty
# Copyrights reserved v-1.1

cd /usr/bin/
wget https://github.com/nu11secur1ty/Linux_hardening_and_security/raw/master/Kernel-sec-modules_by_nu11secur1ty/Modules/LSM/nu11secur1ty-sec/nu11secur1ty/insblpatch
cat > insblpatchmod << EOF
#!/usr/bin/bash
         sleep 3;
         insblpatch
exit 0;
EOF
chmod a+x insblpatchmod
chmod a+x insblpatch
         cd /etc/systemd/system/
                  touch insbl_mod_patch.service
         cat > insbl_mod_patch.service << EOF
[Unit]
Description=insbl_mod_patch systemd service.

[Service]
Type=simple
ExecStart=/bin/bash /usr/bin/insblpatchmod

[Install]
WantedBy=multi-user.target
EOF
         systemctl daemon-reload
         chmod 644 /etc/systemd/system/insbl_mod_patch.service
                           sleep 3;
                  systemctl enable insbl_mod_patch.service
                  systemctl start insbl_mod_patch.service
                  
         exit 0;
