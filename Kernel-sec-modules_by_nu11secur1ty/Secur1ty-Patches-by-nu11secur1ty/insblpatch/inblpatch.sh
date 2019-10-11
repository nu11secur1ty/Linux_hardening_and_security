#!/usr/bin/bash
cd /usr/bin/
wget https://github.com/nu11secur1ty/Linux_hardening_and_security/blob/master/Kernel-sec-modules_by_nu11secur1ty/Modules/LSM/nu11secur1ty-sec/nu11secur1ty/insblpatch
cat > insblpatch << EOF
  #!/usr/bin/bash
  sleep 15;
  ./insblpatch
 exit 0;
EOF
