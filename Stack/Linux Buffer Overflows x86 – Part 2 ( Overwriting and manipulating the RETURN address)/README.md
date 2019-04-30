# Linux Buffer Overflows x86 – Part 2 ( Overwriting and manipulating the RETURN address)
![](https://github.com/nu11secur1ty/Linux_hardening_and_security/blob/master/Stack/Linux%20Buffer%20Overflows%20x86%20%E2%80%93%20Part%202%20(%20Overwriting%20and%20manipulating%20the%20RETURN%20address)/wall/wall.jpg)

Hello Friends, this is the 2nd part of the Linux x86 Buffer Overflows. First of all I want to apologize for such a long delay after the First blog of this series, there were personal and professional issues going on in my life (Well who hasn’t got them? Meh?).

In the previous part we learned about the Process Memory, Stack Region, Stack Operations, Stack Registers, Attempting Buffer Overflow, Overwriting Buffer, ESP and EIP.


- So, Whats Next ?

Till now we have only overwritten the buffer. We haven’t really exploit anything yet. You may have read articles or PoC where Buffer Overflow is used to escalate privileges or it is used to get a reverse shell over the network from a vulnerable HTTP Server. Buffer Overflow is mainly used to execute arbitrary commands on the vulnerable system.

So, we will try to execute arbitrary commands by using this exploit technique.

In this blog, we will mainly focus on how to overwrite the return address to manipulate the flow of control and program execution.

Lets see this in more detail….

We will use a simple program to manipulate its intended output by changing the RETURN address.

(The following example is same as the AlephOne’s famous article on Stack Smashing with some modifications for a better and easy understanding)

Program:
