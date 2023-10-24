#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>

int main(int argc,char*argv[])
{
    int rc=fork();
    if(rc<0)
    {
        fprintf(stderr,"fork failed\n");
        exit(1);
    }
    else if(rc==0)
    {
        printf("hello,i am child (pid:%d)\n",(int)getpid());
        int res=wait(NULL);
        printf("wait finish,res=%d\n",res);
    }
    else
    {
        printf("hello,i am parent of %d (pid:%d)\n",rc,(int)getpid());
    }
    return 0;
}