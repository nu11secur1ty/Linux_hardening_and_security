- in htaccess

```bash
<ifModule mpm_prefork_module>
    MaxSpareServers      5
    ServerLimit          40
    StartServers          2
    MaxClients          1000
    MinSpareThreads      25
    MaxSpareThreads      75
    ThreadsPerChild      25
    MaxRequestsPerChild   0
</ifModule>
        Timeout 60
```
