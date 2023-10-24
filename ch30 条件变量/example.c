#include <pthread.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

volatile int done=0;
pthread_mutex_t m=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t c=PTHREAD_COND_INITIALIZER;

void thr_exit(){
    pthread_mutex_lock(&m);
    done=1;
    pthread_cond_signal(&c);
    pthread_mutex_unlock(&m);
}

void *child(void *arg){
    printf("child\n");
    thr_exit();
    return NULL;
}

void thr_join(){
    pthread_mutex_lock(&m);
    while(done==0)
        pthread_cond_wait(&c,&m);
    pthread_mutex_unlock(&m);
}

int main(){
    printf("parent begin\n");
    pthread_t c;
    int rc=pthread_create(&c,NULL,child,NULL);
    assert(rc==0);
    // 这里不断自旋直到子线程执行结束
    // while(done==0);
    // pthread_join(c,NULL);
    thr_join();
    printf("parent end\n");
    return 0;
}
