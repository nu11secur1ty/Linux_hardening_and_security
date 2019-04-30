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

```c
void function()

{

char buffer[5]= “ABCDE”;

}

void main()

{

int random;

random = 0;

function();

random = 1;

printf("The value of random is: %d\n",random);

}
```

This is a very simple program where the variable random is assigned a value ‘0’, then a function named function is called, the flow is transferred to the function() and it returns to the main() after executing its instructions. Then the variable random is assigned a value ‘1’ and then the current value of random is printed on the screen.

Simple program, we already know its output i.e 1.

![](https://github.com/nu11secur1ty/Linux_hardening_and_security/blob/master/Stack/Linux%20Buffer%20Overflows%20x86%20%E2%80%93%20Part%202%20(%20Overwriting%20and%20manipulating%20the%20RETURN%20address)/wall/1.png)

But, what if we want to skip the instruction random=1; ?

That means, when the function() call returns to the main(), it will not perform the assignment of value ‘1’ to random and directly print the value of random as ‘0’.

So how can we achieve this?

Lets fire up GDB and see how the stack looks like for this program.

(I won’t be explaining each and every instruction, I have already done this in the previous blog. I will only go through the instructions which are important to us. For better understanding of how the stack is setup, refer to the previous blog.)

In GDB, first we disassemble the main function and look where the flow of the program is returned to main() after the function() call is over and also the address where the assignment of value ‘1’ to random takes place.

![](https://github.com/nu11secur1ty/Linux_hardening_and_security/blob/master/Stack/Linux%20Buffer%20Overflows%20x86%20%E2%80%93%20Part%202%20(%20Overwriting%20and%20manipulating%20the%20RETURN%20address)/wall/2.png)

-> At the address 0x08048430, we can see the value ‘0’ is assigned to random.

-> Then at the address 0x08048437 the function() is called and the flow is redirected to the actual place where the function() resides in memory at 0x804840b address.

-> After the execution of function() is complete, it returns the flow to the main() and the next instruction which gets executed is the assignment of value ‘1’ to random which is at address 0x0804843c.

->If we want to skip past the instruction random=1; then we have to redirect the flow of program from 0x08048437 to 0x08048443. i.e after the completion of function() the EIP should point to 0x08048443 instead of 0x0804843c.

To achieve this, we will make some slight modifications to the function(), so that the return address should point to the instruction which directly prints the random variable as ‘0’.

Lets take a look at the execution of the function() and see where the EIP points.


![](https://github.com/nu11secur1ty/Linux_hardening_and_security/blob/master/Stack/Linux%20Buffer%20Overflows%20x86%20%E2%80%93%20Part%202%20(%20Overwriting%20and%20manipulating%20the%20RETURN%20address)/wall/3.png)


-> As of now there is only a char array of 5 bytes inside the function(). So, nothing important is going on in this function call.

-> We set a breakpoint at function() and step through each instruction to see what the EIP points after the function() is exectued completely.

-> Through the command info regsiters eip we can see the EIP is pointing to the address 0x0804843c which is nothing but the instruction random=1;

Lets make this happen!!!

![](https://github.com/nu11secur1ty/Linux_hardening_and_security/blob/master/Stack/Linux%20Buffer%20Overflows%20x86%20%E2%80%93%20Part%202%20(%20Overwriting%20and%20manipulating%20the%20RETURN%20address)/wall/4.png)








