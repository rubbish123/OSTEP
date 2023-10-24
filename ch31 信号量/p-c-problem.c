#include <pthread.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <semaphore.h>

#define MAX 10

int buffer[MAX];
int fill=0,use=0;
sem_t empty,full,mutex;

void put(int value){
    buffer[fill]=value;
    fill=(fill+1)%MAX;
}

int get(){
    int tmp=buffer[use];
    use=(use+1)%MAX;
    return tmp;
}

void *producer(void *arg){
    int i=0;
    while(1){
        sem_wait(&empty);
        sem_wait(&mutex);
        put(i);
        sem_post(&mutex);
        sem_post(&full);
        printf("put:%d\n",i);
        i++;
    }
}

void *consumer(void *arg){
    while(1){
        sem_wait(&full);
        sem_wait(&mutex);
        int tmp=get();
        sem_post(&mutex);
        sem_post(&empty);
        printf("get:%d\n",tmp);
    }
}

int main(){
    sem_init(&empty,0,MAX);
    sem_init(&full,0,0);
    sem_init(&mutex,0,1);
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