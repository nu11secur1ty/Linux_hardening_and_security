- Check for rights of the user `root`
```bash
root@kali:~# sudo -l
```
  Output is `ALL ALL ALL`
```
Matching Defaults entries for root on kali:
    env_reset, mail_badpass, secure_path=/usr/local/sbin\:/usr/local/bin\:/usr/sbin\:/usr/bin\:/sbin\:/bin

User root may run the following commands on kali:
    (ALL : ALL) ALL
```

- Disable `sudo` for ***root***
```bash
sed -i 's/root/#root/' /etc/sudoers
```
- Output should be

```bash
root@kali:~# sudo -l
```
  Output should be
```
User root is not allowed to run sudo on kali.
```
- MOre setup, soon 
# BR nu11secur1ty
