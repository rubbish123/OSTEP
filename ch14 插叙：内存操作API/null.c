#include <stdio.h>
#include <stdlib.h>

int main(){
    int *a=NULL;
    // Segmentation fault
    printf("%d\n",*a);
    return 0;
}