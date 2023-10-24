#include <stdio.h>
#include <stdlib.h>

typedef struct V_int{
    int capacity;
    int size;
    int *data;
}vector;

int append(vector *v,int x){
    if(v->size>v->capacity*0.7){
        v->capacity=v->capacity*2;
        v->data=(int*)realloc(v->data,v->capacity*sizeof(int));
    }
    v->data[v->size]=x;
    v->size++;
    return v->size;
}

int main(){
    vector v={
        .capacity=10,
        .size=0,
        .data=(int*)malloc(10*sizeof(int))
    };
    for(int i=0;i<20;i++)
        append(&v,i);
    for(int i=0;i<v.size;i++)
        printf("%d ",v.data[i]);
    printf("\n");
    return 0;
}