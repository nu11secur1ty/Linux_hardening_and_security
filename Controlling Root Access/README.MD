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
 
 
Allowing Root Access
If the users within an organization are trusted and computer-literate, then allowing them root access may not be an issue. Allowing root access by users means that minor activities, like adding devices or configuring network interfaces, can be handled by the individual users, leaving system administrators free to deal with network security and other important issues.
On the other hand, giving root access to individual users can lead to the following issues:

    Machine Misconfiguration — Users with root access can misconfigure their machines and require assistance to resolve issues. Even worse, they might open up security holes without knowing it.
    Running Insecure Services — Users with root access might run insecure servers on their machine, such as FTP or Telnet, potentially putting usernames and passwords at risk. These services transmit this information over the network in plain text.
    Running Email Attachments As Root — Although rare, email viruses that affect Linux do exist. A malicious program poses the greatest threat when run by the root user.
    Keeping the audit trail intact — Because the root account is often shared by multiple users, so that multiple system administrators can maintain the system, it is impossible to figure out which of those users was root at a given time. When using separate logins, the account a user logs in with, as well as a unique number for session tracking purposes, is put into the task structure, which is inherited by every process that the user starts. When using concurrent logins, the unique number can be used to trace actions to specific logins. When an action generates an audit event, it is recorded with the login account and the session associated with that unique number. Use the aulast command to view these logins and sessions. The --proof option of the aulast command can be used suggest a specific ausearch query to isolate auditable events generated by a particular session. For more information about the Audit system, see Chapter 6, System Auditing. 

4.2.3. Limiting Root Access
Rather than completely denying access to the root user, the administrator may want to allow access only through setuid programs, such as su or sudo. For more information on su and sudo, see the Gaining Privileges chapter in Red Hat Enterprise  Linux 7 System Administrator's Guide, and the su(1) and sudo(8) man pages.
4.2.4. Enabling Automatic Logouts
When the user is logged in as root, an unattended login session may pose a significant security risk. To reduce this risk, you can configure the system to automatically log out idle users after a fixed period of time.

    As root, add the following line at the beginning of the /etc/profile file to make sure the processing of this file cannot be interrupted:

    trap "" 1 2 3 15

    As root, insert the following lines to the /etc/profile file to automatically log out after 120 seconds:

    export TMOUT=120
    readonly TMOUT

    The TMOUT variable terminates the shell if there is no activity for the specified number of seconds (set to 120 in the above example). You can change the limit according to the needs of the particular installation. 

4.2.5. Securing the Boot Loader
The primary reasons for password protecting a Linux boot loader are as follows:

    Preventing Access to Single User Mode — If attackers can boot the system into single user mode, they are logged in automatically as root without being prompted for the root password.

    Warning
    Protecting access to single user mode with a password by editing the SINGLE parameter in the /etc/sysconfig/init file is not recommended. An attacker can bypass the password by specifying a custom initial command (using the init= parameter) on the kernel command line in GRUB 2. It is recommended to password-protect the GRUB 2 boot loader, as described in the Protecting GRUB 2 with a Password chapter in Red Hat Enterprise Linux 7 System Administrator's Guide.
    Preventing Access to the GRUB 2 Console — If the machine uses GRUB 2 as its boot loader, an attacker can use the GRUB 2 editor interface to change its configuration or to gather information using the cat command.
    Preventing Access to Insecure Operating Systems — If it is a dual-boot system, an attacker can select an operating system at boot time, for example DOS, which ignores access controls and file permissions. 

Red Hat Enterprise Linux 7 includes the GRUB 2 boot loader on the Intel 64 and AMD64 platform. For a detailed look at GRUB 2, see the Working With the GRUB 2 Boot Loader chapter in Red Hat Enterprise  Linux 7 System Administrator's Guide.
4.2.5.1. Disabling Interactive Startup
Pressing the I key at the beginning of the boot sequence allows you to start up your system interactively. During an interactive startup, the system prompts you to start up each service one by one. However, this may allow an attacker who gains physical access to your system to disable the security-related services and gain access to the system.
To prevent users from starting up the system interactively, as root, disable the PROMPT parameter in the /etc/sysconfig/init file:

PROMPT=no

4.2.6. Protecting Hard and Symbolic Links
To prevent malicious users from exploiting potential vulnerabilities caused by unprotected hard and symbolic links, Red Hat Enterprise Linux 7 includes a feature that only allows links to be created or followed provided certain conditions are met.
In case of hard links, one of the following needs to be true:

    The user owns the file to which they link.
    The user already has read and write access to the file to which they link. 

In case of symbolic links, processes are only permitted to follow links when outside of world-writeable directories with sticky bits, or one of the following needs to be true:

    The process following the symbolic link is the owner of the symbolic link.
    The owner of the directory is the same as the owner of the symbolic link. 

This protection is turned on by default. It is controlled by the following options in the /usr/lib/sysctl.d/50-default.conf file:

fs.protected_hardlinks = 1
fs.protected_symlinks = 1

To override the default settings and disable the protection, create a new configuration file called, for example, 51-no-protect-links.conf in the /etc/sysctl.d/ directory with the following content:

fs.protected_hardlinks = 0
fs.protected_symlinks = 0

Note
Note that in order to override the default system settings, the new configuration file needs to have the .conf extension, and it needs to be read after the default system file (the files are read in lexicographic order, therefore settings contained in a file with a higher number at the beginning of the file name take precedence).
See the sysctl.d(5) manual page for more detailed information about the configuration of kernel parameters at boot using the sysctl mechanism. 
