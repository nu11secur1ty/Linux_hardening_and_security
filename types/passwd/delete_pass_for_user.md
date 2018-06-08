![](https://github.com/nu11secur1ty/Linux_hardening_and_security/blob/master/types/passwd/password.jpg)

![](https://s19.postimg.cc/bw0vqjmib/Suse_Logo_580x224_tcm21_102997.png) ![](https://s19.postimg.cc/r7aor5jub/debian-logo.png)




# Delete user password
```bash
passwd --delete username
```
# Check line number from ***/etc/passwd*** and search your number ;)
```bach
cat -n /etc/passwd
```
# Delete line which you must remove using "sed" after delete the user if do this.
```bash
sed -i.bak -e '_your num"d"_' /your/file
sed -i.bak -e '38d' /etc/passwd
```
# Clean ***/var/mail/_your_user_***
```bash
rm /var/mail/_user_name
```
# Check if user pass is exist
```bash
cat /etc/passwd | grep _your_user
```

                           ***CREATING PASSWORD, WITHOUT LOSING ANY DATA OF THIS USER***
                           
-------------------------------------------------------------------------------------

# Create password for your again without home dir:
```bash
useradd gancho
```
# Give to him  a password
```bash
passwd gancho
```
# Check again if password existing
```bash
cat /etc/passwd | grep gancho
```
- Output must be
```bash
gancho:x:1001:100::/home/gancho:/bin/bash
```
# ***NOTE: This user*** gancho ***is the same, and he has it already a*** home***directory!***

# Feel sec, with nu11secur1ty ;)
