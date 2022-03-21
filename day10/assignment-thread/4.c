/*
4. Write a program where pthread task displays the thread id and also prints the calling
process pid.
*/
#include<stdio.h>
#include<pthread.h>

pthread_t tid;

void *thr1(void *arg){
    printf("in the thread\n");
    printf("thread with id:%ld \n",pthread_self());
}

int main(){
    int ret;
    ret=pthread_create(&tid,NULL,thr1,NULL);

    pthread_join(tid,NULL);

    printf("now calling process id:%ld \n",pthread_self());
    printf("main ended\n");
    return 0;
}