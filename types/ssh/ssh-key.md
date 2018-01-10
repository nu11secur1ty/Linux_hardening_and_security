# Generate the key

```
ssh-keygen -t rsa -b _your_bit_key
```
- IMPORTANT: BETTER USE "-b" (above 5000) 

# Export and create a file "authorized_keys" if you don't have it

```
cat ~/.ssh/id_rsa.pub | ssh user@x.x.x.x "mkdir -p ~/.ssh && cat >>  ~/.ssh/authorized_keys"
```
# Adding the next key on the client machine if you already have it him somewhere on this machine.

```
echo -e "_your_key_" >> ~/.ssh/authorized_keys
```


# Permit root login

- Change the following :
```
vim /etc/ssh/sshd_config

```
```
PasswordAuthentication no
PermitRootLogin without-password
```

# Restart your ssh server

```
service ssh restart
systemctl restart ssh
```

