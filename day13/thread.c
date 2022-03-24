#include<stdio.h>
#include<pthread.h>

pthread_t tid;

void *thr1(void *arg){
    printf("in the thread\n");
}

int main(){
    int ret;
    ret=pthread_create(&tid,NULL,thr1,NULL);

    pthread_join(tid,NULL);
    printf("main ended\n");
    return 0;
}