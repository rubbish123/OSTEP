#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc,char*argv[])
{
    printf("hello world (pid:%d)\n",(int)getpid());
    int x=100;
    int rc=fork();
    if(rc<0)
    {
        fprintf(stderr,"fork failed\n");
        exit(1);
    }
    else if(rc==0)
    {
        printf("hello,i am child (pid:%d)\n",(int)getpid());
        printf("child:x=%d\n",x);
        x=20;
        printf("child:x=%d\n",x);
    }
    else
    {
        int wc=wait(NULL);
        printf("hello,i am parent of %d (wc:%d) (pid:%d)\n",rc,wc,(int)getpid());
        printf("parent:x=%d\n",x);
        x=30;
        printf("parent:x=%d\n",x);
    }
    return 0;
}