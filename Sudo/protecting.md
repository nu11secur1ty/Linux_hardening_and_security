- Check for rights of the user `root`
```bash
root@kali:~# sudo -l
```
  Output is `ALL ALL ALL`
   Output:
```
Matching Defaults entries for root on kali:
    env_reset, mail_badpass, secure_path=/usr/local/sbin\:/usr/local/bin\:/usr/sbin\:/usr/bin\:/sbin\:/bin

User root may run the following commands on kali:
    (ALL : ALL) ALL
```

- Disable `sudo` for ***root***
  
  OS: Debian, Kali, Ubuntu

-------------------------------------------------------------
```bash
sed -i 's/root/#root/' /etc/sudoers
```
- Checking

```bash
root@kali:~# sudo -l
```
  Output should be
```
User root is not allowed to run sudo on kali.
```
------------------------------------------------------------

# For SUSE
- Edit

```bash
vim /etc/sudoers
```
- Comment `root`, `Defaults` and `ALL`
```bash
#Defaults targetpw   # ask for the password of the target user i.e. root
#ALL   ALL=(ALL) ALL   # WARNING! Only use this together with 'Defaults targetpw'!

##
## Runas alias specification
##

##
## User privilege specification
##
#root ALL=(ALL) ALL
```
- Output 
```bash
User root is not allowed to run sudo on suseuser.
```
- MOre setup, soon 
# BR nu11secur1ty
