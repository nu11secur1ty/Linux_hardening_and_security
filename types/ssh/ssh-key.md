# Generate the key

```
ssh-keygen -t rsa -b _your_bit_key
```
# Export and create a file "authorized_keys" if you don't have it

```
cat ~/.ssh/id_rsa.pub | ssh user@x.x.x.x "mkdir -p ~/.ssh && cat >>  ~/.ssh/authorized_keys"
```

# Restart your ssh server

```
service ssh restart
systemctl restart ssh
```

