#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

int main(int argc,char *argv[]){
    if(argc!=3){
        fprintf(stderr,"argu error\n");
        exit(0);
    }
    printf("pid:%d\n",(int)getpid());
    struct timeval begin,now;
    int mem=atoi(argv[1])*1024*1024;
    int *arr=malloc(mem);
    if(!arr){
        fprintf(stderr,"malloc error\n");
        exit(0);
    }
    gettimeofday(&begin,NULL);
    while(1){
        gettimeofday(&now,NULL);
        if(now.tv_sec-begin.tv_sec>atoi(argv[2]))
            break;
        for(int i=0;i<mem/4;i++)
            arr[i]=i;
    }
    free(arr);
    return 0;
}
