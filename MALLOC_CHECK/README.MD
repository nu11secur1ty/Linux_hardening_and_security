## Diagnosing Memory Heap Corruption in glibc with MALLOC_CHECK_

This document (3113982) is provided subject to the disclaimer at the end of this document.

Environment
Novell eDirectory 8.7.3 for Linux
Novell eDirectory 8.8 for Linux
Novell Open Enterprise Server (Linux based)
Novell SUSE Linux Enterprise Server 9
Novell SUSE Linux Enterprise Server 10
Novell SUSE Linux Enterprise Server 11
 
Situation
The GNU C Library ( glibc ) is the standard C library on Linux Systems. Other C libraries exist and are sometimes used for special purposes (such as very small subsets of the standard C libraries used for embedded systems and bootstrapping), but glibc is the standard C library on all Linux distributions.
 
The glibc includes three simple memory-checking tools. The two, mcheck() and MALLOC_CHECK_ , enforce heap data structure consistency checking, and the third, mtrace() , traces memory allocation and deallocation for later processing. When memory is allocated from the heap , the memory management functions need someplace to store information about the allocations. That place is the heap itself; this means that the heap is composed of alternating areas of memory that are used by the program and by the memory management functions themselves. This means that buffer overflows or underruns can actually damage the data structures that the memory management functions use to keep track of what memory has been allocated.
 
When this happens, all bets are off, except that is pretty good bet that the memory management functions will eventually cause the program to crash. If we set the MALLOC_CHECK_ environment variable, a different and somewhat slower set of memory management functions is chosen that is more tolerant of errors and can check for calling free() more than once on the same pointer for single-byte buffer overflows.
 
 
Resolution
Setting MALLOC_CHECK_ :

- `If MALLOC_CHECK_ is set to 0 (zero)` , the memory management functions are simply more tolerant of error but do not give warnings.
Maybe be useful if we are prevented from finding one memory bug by another that is not convenient to fix at the moment; it might allow us to use other tools to chase down the other memory bug.
It may also be useful if you are running code that works on another system but not on Linux and we want a quick workaround that may allow the code to function temporarily, before you have the chance to resolve the error.
```
export MALLOC_CHECK_=0
```
---------------------------------------------------------------------------------------

- `If MALLOC_CHECK_ is set to 1 (one)` , the memory management functions print out warning messages on standard error when they notice problems.
It is useful if we are not aware of any problems and just want to be notified if any problem exist.

```
export MALLOC_CHECK_=1
```
---------------------------------------------------------------------------------------
- `If MALLOC_CHECK_ is set to 2 (two)` , the memory management functions call abort() when they notice problems.
This is most useful from inside the debugger or a shell starting an application or daemon, because it allows you to get a backtrace as soon as the memory management functions discover the error, which will get us closest to the point at which the error has happened .
It is useful if we get a core caused by a memory corruption, we would have more information about memory allocation therefore, making things better for troubleshooting where we need to find out which application overwrote a memory address.
We can still combine settings 1 and 2 and `MALLOC_CHECK_ is set to 3 (three)` , where it will print out the warning messages on standard error (1) and will call abort() when problems are noticed (2) .  
Additional Information
Setting MALLOC_CHECK_ examples:

1. Add the following to the /etc/init.d/pre_ndsd_start file:
```
export MALLOC_CHECK_=2
```
This setting should be used for debugging purposes only . Due to the performance hit caused by MALLOC_CHECK_ ( which could be up to 25% in some cases ), it is recommended to comment it out as soon as the needed core file is taken.


NAMCD script (/etc/init.d/namcd):
...
# Template configuration variables

prefix =/usr
exec_prefix =/usr
sbindir =/usr/sbin
bindir =/usr/bin
initdir =/etc/init.d
```
export MALLOC_CHECK_ = 2
```
userID = `id`
...
This setting should be used for debugging purposes only . Due to the performance hit caused by MALLOC_CHECK_ ( which could be up to 30% in some cases ), it is recommended to comment it out as soon as the needed core file is taken.

## Permanent setup
```bash
echo "export MALLOC_CHECK_=0" >> /etc/profile
```
## More for the `glibc`bug

[link](https://www.ibm.com/support/pages/archecker-fails-error-message-glibc-detected-archecker-free-invalid-pointer-0x00007fff4ea8fec9)
