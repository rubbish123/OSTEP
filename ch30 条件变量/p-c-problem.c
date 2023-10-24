#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 10
int buffer[MAX];
int fi=0;
int use=0;
int count=0;

void put(int value){
    buffer[fi]=value;
    fi=(fi+1)%MAX;
    count++;
}

int get(){
    int tmp=buffer[use];
    use=(use+1)%MAX;
    count--;
    return tmp;
}

pthread_cond_t empty,fill;
pthread_mutex_t mutex;

void *producer(void *arg){
    int i=0;
    while(1){
        pthread_mutex_lock(&mutex);
        while(count==MAX)
            pthread_cond_wait(&empty,&mutex);
        put(i);
        i++;
        pthread_cond_signal(&fill);
        pthread_mutex_unlock(&mutex);
        printf("put:%d,count:%d\n",i-1,count);
    }
}

void *consumer(void *arg){
    int i=0;
    while(1){
        pthread_mutex_lock(&mutex);
        while(count==0)
            pthread_cond_wait(&fill,&mutex);
        int tmp=get();
        pthread_cond_signal(&empty);
        pthread_mutex_unlock(&mutex);
        printf("get:%d,count:%d\n",tmp,count);
    }
}

int main(){
    pthread_t p1,p2,p3,c1,c2,c3;
    pthread_create(&p1,NULL,producer,NULL);
    pthread_create(&p2,NULL,producer,NULL);
    pthread_create(&p3,NULL,producer,NULL);
    pthread_create(&c1,NULL,consumer,NULL);
    pthread_create(&c2,NULL,consumer,NULL);
    pthread_create(&c3,NULL,consumer,NULL);
    pthread_join(p1,NULL);
    pthread_join(p2,NULL);
    pthread_join(p3,NULL);
    pthread_join(c1,NULL);
    pthread_join(c2,NULL);
    pthread_join(c3,NULL);
    return 0;
}
