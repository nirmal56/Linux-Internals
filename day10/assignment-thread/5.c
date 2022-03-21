/*
5.Write a program that implements threads synchronization using mutex techniques.
*/
#include<stdio.h>
#include<pthread.h>

int sharedvar=5;
pthread_mutex_t my_mutex;

void *thread_inc(void *arg){
    pthread_mutex_lock(&my_mutex);
    sharedvar++;
    printf("incremented:%d\n",sharedvar);
    pthread_mutex_unlock(&my_mutex);
}

void *thread_dec(void *arg){
    pthread_mutex_lock(&my_mutex);
    sharedvar--;
    printf("decremented:%d\n",sharedvar);
    pthread_mutex_unlock(&my_mutex);
}

int main(void){
    pthread_t tid,tid2;
    pthread_mutex_init(&my_mutex,NULL);

    int ret = pthread_create(&tid,NULL,thread_inc,NULL);
    int ret2 = pthread_create(&tid2,NULL,thread_dec,NULL);

    pthread_join(tid,NULL);
    pthread_join(tid2,NULL);

    printf("shared variable is now:%d\n",sharedvar);
    return 0;
}