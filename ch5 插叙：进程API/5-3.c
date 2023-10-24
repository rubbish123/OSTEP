#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc,char*argv[])
{
    printf("hello world (pid:%d)\n",(int)getpid());
    int rc=fork();
    if(rc<0)
    {
        fprintf(stderr,"fork failed\n");
        exit(1);
    }
    else if(rc==0)
    {
        printf("hello,i am child (pid:%d)\n",(int)getpid());
        char *myargs[3];
        myargs[0]=strdup("wc");
        myargs[1]=strdup("5-3.c");
        myargs[2]=NULL;
        execvp(myargs[0],myargs);
    }
    else
    {
        int wc=wait(NULL);
        printf("hello,i am parent of %d (wc:%d) (pid:%d)\n",rc,wc,(int)getpid());
    }
    return 0;
}