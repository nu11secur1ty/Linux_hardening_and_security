# Controlling Root Access

When administering a home machine, the user must perform some tasks as the root user or by acquiring effective root privileges using a setuid program, such as sudo or su. A setuid program is one that operates with the user ID (UID) of the program's owner rather than the user operating the program. Such programs are denoted by an s in the owner section of a long format listing, as in the following example: 

```bash
~]$ ls -l /bin/su
-rwsr-xr-x. 1 root root 34904 Mar 10  2011 /bin/su
```
- Note
`The s may be upper case or lower case. If it appears as upper case, it means that the underlying permission bit has not been set`.

For the system administrator of an organization, however, choices must be made as to how much administrative access users within the organization should have to their machines. Through a PAM module called pam_console.so, some activities normally reserved only for the root user, such as rebooting and mounting removable media, are allowed for the first user that logs in at the physical console. However, other important system administration tasks, such as altering network settings, configuring a new mouse, or mounting network devices, are not possible without administrative privileges. As a result, system administrators must decide how much access the users on their network should receive. 

- Disallowing Root Access
If an administrator is uncomfortable allowing users to log in as root for these or other reasons, the root password should be kept secret, and access to runlevel one or single user mode should be disallowed through boot loader password protection.

 The following are four different ways that an administrator can further ensure that root logins are disallowed:

Changing the root shell
    To prevent users from logging in directly as root, the system administrator can set the root account's shell to `/sbin/nologin` in the `/etc/passwd` file. 
    
- Disabling the Root Shell

```
 Prevents access to a root shell and logs any such attempts. The following programs are prevented from accessing the root account:

    login
    gdm
    kdm
    xdm
    su
    ssh
    scp
    sftp 
    
    ------------------------------------------------------
```

Programs that do not require a shell, such as FTP clients, mail clients, and many setuid programs. The following programs are not prevented from accessing the root account:
```
sudo
FTP clients
Email clients 
```

- Disabling root access using any console device (tty)
    To further limit access to the root account, administrators can disable root logins at the console by editing the `/etc/securetty` file. This file lists all devices the root user is allowed to log into. If the file does not exist at all, the root user can log in through any communication device on the system, whether through the console or a raw network interface. This is dangerous, because a user can log in to their machine as root using Telnet, which transmits the password in plain text over the network.
    By default, Red Hat Enterprise Linux 7's `/etc/securetty` file only allows the root user to log in at the console physically attached to the machine. To prevent the root user from logging in, remove the contents of this file by typing the following command at a shell prompt as root: 
    
```bash
echo > /etc/securetty
```

To enable securetty support in the KDM, GDM, and XDM login managers, add the following line: 

```bash
auth [user_unknown=ignore success=ok ignore=ignore default=bad] pam_securetty.so
```
to the files listed below: 

- /etc/pam.d/gdm
- /etc/pam.d/gdm-autologin
- /etc/pam.d/gdm-fingerprint
- /etc/pam.d/gdm-password
- /etc/pam.d/gdm-smartcard
- /etc/pam.d/kdm
- /etc/pam.d/kdm-np
- /etc/pam.d/xdm 
    
    
# Warning
    
A blank `/etc/securetty` file does not prevent the root user from logging in remotely using the OpenSSH suite of tools because the console is not opened until after authentication. 


# Disabling Root Logins


 Prevents access to the root account using the console or the network. The following programs are prevented from accessing the root account:

    login
    gdm
    kdm
    xdm
    Other network services that open a tty 
 
 -------------------------------------------------
 
  Programs that do not log in as root, but perform administrative tasks through setuid or other mechanisms. The following programs are not prevented from accessing the root account:

    su
    sudo
    ssh
    scp
    sftp 
---------------------------------------------------


- Disabling root SSH logins

To prevent root logins through the SSH protocol, edit the SSH daemon's configuration file, `/etc/ssh/sshd_config`, and change the line that reads: 

```bash
#PermitRootLogin yes
```
to read as follows: 

```bash
PermitRootLogin no
```
-------------------------------------------------------


- Disabling Root SSH Logins


 Prevents root access using the OpenSSH suite of tools. The following programs are prevented from accessing the root account:

    ssh
    scp
    sftp 
-------------------------------------------------------

Programs that are not part of the OpenSSH suite of tools. 


- PAM to limit root access to services

PAM, through the `/lib/security/pam_listfile.so` module, allows great flexibility in denying specific accounts. The administrator can use this module to reference a list of users who are not allowed to log in. To limit root access to a system service, edit the file for the target service in the `/etc/pam.d/` directory and make sure the `pam_listfile.so` module is required for authentication.
The following is an example of how the module is used for the vsftpd FTP server in the `/etc/pam.d/vsftpd` PAM configuration file (the \ character at the end of the first line is not necessary if the directive is on a single line): 
    
```bash
auth   required   /lib/security/pam_listfile.so   item=user \
sense=deny file=/etc/vsftpd.ftpusers onerr=succeed
```
 This instructs PAM to consult the /etc/vsftpd.ftpusers file and deny access to the service for any listed user. The administrator can change the name of this file, and can keep separate lists for each service or use one central list to deny access to multiple services.
If the administrator wants to deny access to multiple services, a similar line can be added to the PAM configuration files, such as `/etc/pam.d/pop` and `/etc/pam.d/imap` for mail clients, or `/etc/pam.d/ssh` for SSH clients.
For more information about PAM, see The Linux-PAM System Administrator's Guide, located in the `/usr/share/doc/pam-<version>/html/` directory. 
 
  Prevents root access to network services that are PAM aware. The following services are prevented from accessing the root account:

    login
    gdm
    kdm
    xdm
    ssh
    scp
    sftp
    FTP clients
    Email clients
    Any PAM aware services 
 ---------------------------------------------------------------------------
 
 Programs and services that are not PAM aware. 
 
 
