/*
2.Write a program where thread cancel itself.(use pthread_cancel())
*/
#include<stdio.h>
#include<pthread.h>

pthread_t tid;

void *thr1(void *arg){
    printf("in the thread\n");
    printf("thread with id: %ld cancelled\n",pthread_self());
    pthread_cancel(tid);
}

int main(){
    int ret;
    ret=pthread_create(&tid,NULL,thr1,NULL);

    pthread_join(tid,NULL);

    printf("now id is:%ld \n",pthread_self());
    printf("main ended\n");
    return 0;
}