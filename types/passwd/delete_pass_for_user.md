# Command to delete user password under Linux
```bash
passwd --delete username
```
# Check line number from ***/etc/passswd***
```bach
cat -n /etc/passwd
```
# Delete line which you must remove using "sed" after delete the user if do this.
```bash
sed -i.bak -e '_your num"d"_' /your/file
sed -i.bak -e '38' /etc/passwd
```
# Clean ***/var/mail/_your_user_
```bash
rm /var/mail/_user_name
```
# Check if user pass is exist
```bash
cat /etc/passwd | grep _your_user
```

-------------------------------------------------------------------------------------

# Create password again:
```bash
passwd _your_username
```
