# Creating a Chroot Jail for SSH Access

# Setup your user "user"

- So we must setup the group, then add the user. 

```
$ groupadd sshusers
$ adduser -g sshusers user
```

# Setup the jail directories
- The next step is to setup all the directories needed. This needs to emulate the / directory to a bare minimum. That is we need a dev, etc, lib, usr, and bin directory as well as usr/bin/. The base directory has to be owned by root.

```
$ mkdir -p /var/jail/{dev,etc,lib,usr,bin}
$ mkdir -p /var/jail/usr/bin
$ chown root.root /var/jail
```
-  You also need the /dev/null file: 

```
$ mknod -m 666 /var/jail/dev/null c 1 3
```
-  You need to fill up the etc directory with a few minimum files: 

```
$ cd /var/jail/etc
$ cp /etc/ld.so.cache .
$ cp /etc/ld.so.conf .
$ cp /etc/nsswitch.conf .
$ cp /etc/hosts .
```
- Once this is done you need to figure out what commands you want accessible by your limited    users. In this example I only want the users to be able to get into bash and use the ls command. So you must copy the binaries to the jail. 

```
$ cd /var/jail/usr/bin
$ cp /usr/bin/ls .
$ cp /usr/bin/bash .
```

- Now that you've got all the binaries in place, you need to add the proper shared libraries. To find out what libraries are need you can run ldd /path/to/bin. The output looks similar to this: 


```
$ ldd /bin/ls
         linux-gate.so.1 =>    (0xb7f2b000)
         librt.so.1 => /lib/librt.so.1 (0xb7f1d000)
         libacl.so.1 => /lib/libacl.so.1 (0xb7f16000)
         libc.so.6 => /lib/libc.so.6 (0xb7dcf000)
         libpthread.so.0 => /lib/libpthread.so.0 (0xb7db7000)
         /lib/ld-linux.so.2 (0xb7f2c000)
         libattr.so.1 => /lib/libattr.so.1 (0xb7db2000)
```


- Then you have to manually copy each file to the lib directory in your jail. That is a pain. Especially if there is a lot of shared libraries for a binary you want. I came across a useful script called l2chroot which automatically finds the libraries and copies them to your chroot jail. 


```
cd /sbin
wget -O l2chroot http://www.cyberciti.biz/files/lighttpd/l2chroot.txt
chmod +x l2chroot
```
- Edit the l2chroot file and change BASE=”/webroot” to BASE=”/var/jail”. This tells l2chroot where your jail is located so it copies everything to the right place. Now go ahead and run the command on the binaries you want. 


```
l2chroot ls
l2chroot bash
```

# Configure SSHd to Chroot your users

- All that is left is to set a few things in your sshd configuration file. You need to make sure you have at least OpenSSH 4.8p1, because before that they didn't have this nice ChrootDirectory() function. Previously there was a few extra steps you had to take to get it working, but really you should have a newer version anyway. To configure ChrootDirectory add the following to /etc/ssh/sshd_config: 

```
Match group sshusers
          ChrootDirectory /var/jail/
          X11Forwarding no
          AllowTcpForwarding no
```

- Note that this also disables X11Forwarding and does not allow port forwarding. If you want to setup a box to allow secure tunneling for your friends, you may want to change this. 

# Optional Steps

- When you login to your test user, you'll notice a prompt as such: 

```
bash-3-2$
```
- That is not a very useful bash prompt. So if you want something a little better I recommend simply copying the contents of /etc/skel to /var/jail/home/user. This gives you a .bashrc file which sets the PS1 variable to a much nicer looking prompt. Here's what mine looks like: 

```
phrygian:~> echo $PS1
\h:\w>
phrygian:~>
```
# Feel secure with nu11secur1ty.




























































