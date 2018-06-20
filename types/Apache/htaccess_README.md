# Add this in to /usr/share/apache2/icons/
```bash
# Protect icons/README
<Files README.html>
     Order Allow,Deny
     Deny from all
</Files>
```
# Allow reading logs from the browser using .htaccess in exactly node directory.
```bash 
# Web HTaccess
AuthType Basic
AuthName "Password Protected Area"
AuthUserFile /etc/apache2/.htpasswd
Require valid-user
########################################
# Allow .log files to view from browser
<Files ~ "\.log$">
    Order allow,deny
    #Deny from all
    Allow from all
</Files>
```
