#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>

int main(int argc,char*argv[])
{
    int fd=open("./test.txt",O_RDWR|O_TRUNC);
    int rc=fork();
    if(rc<0)
    {
        fprintf(stderr,"fork failed\n");
        exit(1);
    }
    else if(rc==0)
    {
        printf("hello,i am child (pid:%d)\n",(int)getpid());
        printf("hello\n");
    }
    else
    {
        printf("hello,i am parent of %d (pid:%d)\n",rc,(int)getpid());
        printf("goodbye\n");
    }
    return 0;
}