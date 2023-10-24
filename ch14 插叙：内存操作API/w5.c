#include <stdio.h>
#include <stdlib.h>

int main(){
    int *data=malloc(100*sizeof(int));
    if(!data){
        fprintf(stderr,"malloc error\n");
        exit(0);
    }
    data[100]=0;
    return 0;
}