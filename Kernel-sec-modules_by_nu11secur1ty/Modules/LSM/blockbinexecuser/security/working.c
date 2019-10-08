#include <stdio.h>
int main(void)
{
    FILE *myfile;
    char tempstring[1024];
    if(!(myfile=fopen("/etc/passwd","r")))
    {
         fprintf(stderr,"Could not open file\n");
         exit(1);
    }
    while(!feof(myfile))
    {
         fscanf(myfile,"%s\n",tempstring);
         fprintf(stdout,"%s\n",tempstring);
    }
    exit(0);
}
