#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#include <sys/time.h>

int main()
{
    int fd=open("./test.txt",O_RDONLY);
    char buf[16];
    struct timeval begin,end;
    gettimeofday(&begin,NULL);
    for(int i=0;i<1000000;i++)
    {
        read(fd,buf,0);
    }
    gettimeofday(&end,NULL);
    printf("单次执行:%f微秒\n",(float)(end.tv_sec*1000000+end.tv_usec-begin.tv_sec*1000000-begin.tv_usec)/1000000);
    return 0;
}