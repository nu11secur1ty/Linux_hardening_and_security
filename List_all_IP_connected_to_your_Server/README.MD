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


```bash
netstat -tn 2>/dev/null | grep :80 | awk '{print $5}' | cut -d: -f1 | sort | uniq -c | sort -nr | head
```
