- OS: OpenSuse Leap 42.3

***Securing with SuSEfirewall2***
```bash
vim /etc/sysconfig/SuSEfirewall2
```
`Example: "172.20.1.1 172.20.0.0/16 1.1.1.1,icmp 2.2.2.2,tcp,22 2620:113:80c0:8080:10:160:68:136/64,rsync"`

- Add your IP's to restrict specific host by ssh

```bash
FW_TRUSTED_NETS="0.0.0.0 0.0.0.0/29 0.0.0.0,tcp,22"
systemctl restart  SuSEfirewall2
```
