# Secure your transport headers in your .htaccess file
```
RewriteEngine On 
RewriteCond %{SERVER_PORT} 80 
RewriteRule ^(.*)$ https://www.example.com/$1 [R,L]
```

# Check-transport-headers
```  
openssl s_client -connect _your_IP_host:443 -status
```
# Output should be:
```
139933417682240:error:0200206E:system library:connect:Connection timed out:../crypto/bio/b_sock2.c:108:
139933417682240:error:2008A067:BIO routines:BIO_connect:connect error:../crypto/bio/b_sock2.c:109:
connect:errno=110
```
