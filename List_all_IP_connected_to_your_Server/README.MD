# Fast check who want something from you ;)
: 80
```bash
netstat -tn 2>/dev/null | grep :80 | awk '{print $5}' | cut -d: -f1 | sort | uniq -c | sort -nr | head
```

: 8080
```bash
netstat -tn 2>/dev/null | grep :8080 | awk '{print $5}' | cut -d: -f1 | sort | uniq -c | sort -nr | head
```

:22
```bash
netstat -tn 2>/dev/null | grep :22 | awk '{print $5}' | cut -d: -f1 | sort | uniq -c | sort -nr | head
```

:21
```bash
netstat -tn 2>/dev/null | grep :21 | awk '{print $5}' | cut -d: -f1 | sort | uniq -c | sort -nr | head
```

:443
```bash
netstat -tn 2>/dev/null | grep :443 | awk '{print $5}' | cut -d: -f1 | sort | uniq -c | sort -nr | head
```

:3306
```bash
netstat -tn 2>/dev/null | grep :3306 | awk '{print $5}' | cut -d: -f1 | sort | uniq -c | sort -nr | head
```


:33060
```bash
netstat -tn 2>/dev/null | grep :33060 | awk '{print $5}' | cut -d: -f1 | sort | uniq -c | sort -nr | head
```
@nu11secur1ty
