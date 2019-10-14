#include <stdio.h>
#include <stdlib.h>
//Author @nu11secur1ty//

int main(void)
{
/* Unload insmod_blosk module*/
 system("sed -i '/insblpatchmod/d' /etc/profile");
 system("sleep 5;");
  system("telinit 6");
}
