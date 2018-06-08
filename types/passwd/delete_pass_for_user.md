# Command to delete user password under Linux
```bash
passwd --delete username
```
# Check line number from ***/etc/passswd***
```bach
cat -n /etc/passwd
```
# Delete line which you must remove
```bash
ed -i.bak -e '_your num"d"_' /your/file
ed -i.bak -e '38' /etc/passwd
```
