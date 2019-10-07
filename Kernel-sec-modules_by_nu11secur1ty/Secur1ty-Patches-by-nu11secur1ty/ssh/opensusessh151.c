
#include <stdio.h>
#include <stdlib.h>
//Author @nu11secur1ty//

int main(void)
{
 /*Stopping permanently root login, from outside*/
 system("sed -i 's/PermitRootLogin yes/PermitRootLogin no/' /etc/ssh/sshd_config");
 system("rcsshd restart");

}
