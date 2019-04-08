# Doc
Whats a reverse shell? 

Not quite but, you aren’t alone in ignorance. It is surprising that the number of folks that don’t actually know what a reverse shell is. Long story short, it is when one computer connects to another computer but the initiating computer forwards their shell to the destination. It is commonplace that a reverse shell happens during an attack or as part of a pentest. They are scary attacks because it gives an attacker an interactive shell on a machine that they should not have had access to inside of the “hardened” area.

Lets break down how this works. 
First there is a machine listening somewhere on a specific tcp port. In this case using netcat.
