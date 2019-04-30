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

From the previous blog, we came to know about the stack layout. We can see how the top of the stack is aligned, 8 bytes for the buffer, 4 bytes for the EBP, 4 bytes for the RET address and so on (If there is a value passed as parameter in a function then it gets pushed first onto the stack when the function is called).

-> When the function() is called, first the RET address gets pushed onto the stack so the program flow can be maintained after the execution of function().

->Then the EBP gets pushed onto the stack, so the EBP can act as the offset reference point for other instructions to access and calculate the memory addresses.

-> We have char array buffer of 5 bytes, but the memory is allocated in terms of WORD. Basically 1 word=4 bytes. Even if you declare a variable or array of 2 bytes it will be allocated as 4 bytes or 1 word. So, here 5 bytes=2 words i.e 8 bytes.


![](https://github.com/nu11secur1ty/Linux_hardening_and_security/blob/master/Stack/Linux%20Buffer%20Overflows%20x86%20%E2%80%93%20Part%202%20(%20Overwriting%20and%20manipulating%20the%20RETURN%20address)/wall/5.png)


-> So, in our case when inside the function(), the stack will probably be setup as buffer + EBP + RET

-> Now we know that after 12 bytes, the flow of the program will return to main() and the instruction random = 1; will be executed. We want to skip past this instruction by manipulating the RET address to somehow point to the address after 0x0804843c.

->We will now try to manipulate the RET address by doing something like below :-

```c
int *ret;

ret = buffer + 12;
```

Here, we are introducing an int pointer ret, and we are assigning it the starting address of buffer + 12 .i.e (wait lets see this in a diagram)

![](https://github.com/nu11secur1ty/Linux_hardening_and_security/blob/master/Stack/Linux%20Buffer%20Overflows%20x86%20%E2%80%93%20Part%202%20(%20Overwriting%20and%20manipulating%20the%20RETURN%20address)/wall/6.png)


-> So, the ret pointer now ends exactly at the start where the return value is actually stored. Now, we just want to add ret pointer with some value which will change the return value in such a manner that it will skip past the return = 1; instruction.

Lets just go back to the disassembled main function and calculate how much we have to add to the ret pointer to actually skip past the assignment instruction.


![](https://github.com/nu11secur1ty/Linux_hardening_and_security/blob/master/Stack/Linux%20Buffer%20Overflows%20x86%20%E2%80%93%20Part%202%20(%20Overwriting%20and%20manipulating%20the%20RETURN%20address)/wall/7.png)



-> So, we already know we want to skip pass the instruction at address 0x0804843c to address 0x08048443. By subtracting these two address we get 7. So we will add 7 to the return address so that it will point to the instruction at address 0x08048443.

![](https://github.com/nu11secur1ty/Linux_hardening_and_security/blob/master/Stack/Linux%20Buffer%20Overflows%20x86%20%E2%80%93%20Part%202%20(%20Overwriting%20and%20manipulating%20the%20RETURN%20address)/wall/8.png)


So our final code should look like:

```c
void function()

{

char buffer[5]= “ABCDE”;

int *ret;

ret = buffer + 12;

(*ret) += 7;

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









