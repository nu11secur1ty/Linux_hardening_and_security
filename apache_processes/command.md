# List all apache2 pids on debian
```bash
ps auxw | grep bin/apache | awk '{print"-p " $2}'
```
# List all *child* processes Open SUSE leap 42.3, 15.0
```bash
ps auxw | grep sbin/httpd | awk '{print"-p " $2}' | xargs strace
ps auxw | grep sbin/httpd | awk '{print $2}' | awk ' {print "-p "$1}' | xargs strace
```
- **NOTE:** After checking is finished you must restart your Apache2 webserver
