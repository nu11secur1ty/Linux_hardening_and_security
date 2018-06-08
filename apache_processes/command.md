# List all apache2 pids on debian
```bash
ps auxw | grep bin/apache | awk '{print"-p " $2}'
```
