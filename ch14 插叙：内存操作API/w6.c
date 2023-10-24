#include <stdio.h>
#include <stdlib.h>

int main(){
    int *data=malloc(100*sizeof(int));
    if(!data){
        fprintf(stderr,"malloc error\n");
        exit(0);
    }
    free(data);
    printf("data[0]=%d\n",data[0]);
    return 0;
}