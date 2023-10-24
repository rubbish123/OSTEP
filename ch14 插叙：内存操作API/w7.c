#include <stdio.h>
#include <stdlib.h>

int main(){
    int *data=malloc(100*sizeof(int));
    if(!data){
        fprintf(stderr,"malloc error\n");
        exit(0);
    }
    free(&data[27]);
    printf("free data[27]\n");
    return 0;
}