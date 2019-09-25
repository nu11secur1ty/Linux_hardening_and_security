# Disable TRACE method
- in your `httpd.conf` add this line
```bash
TraceEnable off
```
- Test
```bash
$ curl -X TRACE 127.0.0.1
```
- If you are not set up correctly, you should see this:
```bash
TRACE / HTTP/1.1
User-Agent: curl/7.24.0 (x86_64-apple-darwin12.0) libcurl/7.24.0 OpenSSL/0.9.8r zlib/1.2.5
Host: 127.0.0.1
Accept: */*
```
- If everything is ok you should see:
```bash
<!DOCTYPE HTML PUBLIC "-//IETF//DTD HTML 2.0//EN">
<html><head>
<title>405 Method Not Allowed</title>
</head><body>
<h1>Method Not Allowed</h1>
<p>The requested method TRACE is not allowed for the URL /.</p>
</body></html>
```
