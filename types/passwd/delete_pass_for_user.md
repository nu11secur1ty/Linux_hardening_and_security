# Command to delete user password under Linux
```bash
passwd --delete username
```
# Check line number from ***/etc/passswd***
```bach
cat -n /etc/passwd
```
# Delete line which you must remove using "sed"
```bash
sed -i.bak -e '_your num"d"_' /your/file
sed -i.bak -e '38' /etc/passwd
```
# Check if user pass is exist
```bash
cat /etc/passwd | grep _your_user
```
