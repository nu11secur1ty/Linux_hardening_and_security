# searching, for available kernel modules on your system
```bash
find /lib/modules/$(uname -r) -type f -name '*.ko*' | xargs wc -l
```
