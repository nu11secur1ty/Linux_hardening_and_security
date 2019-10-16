#include <stdio.h>
#include <stdlib.h>
//Author @nu11secur1ty//

int main(void)
{
/* Changing the privileges for 'insmod' that user can not be using outside Linux Kernel Module */
 system("cat /proc/insmod_block > /proc/sys/kernel/modules_disabled");
 /* Block insmod Option by nu11secur1ty */
}
