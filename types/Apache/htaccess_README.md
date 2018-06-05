# Add this in to /usr/share/apache2/icons/
```bash
# Protect icons/README
<Files README.html>
     Order Allow,Deny
     Deny from all
</Files>
```
