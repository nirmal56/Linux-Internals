/*
5.Write a program that implements threads synchronization using mutex techniques.
*/
#include<stdio.h>
#include<pthread.h>

int shrdvar=25;
pthread_mutex_t my_mutex;

void *thread_mul(void *arg){
    pthread_mutex_lock(&my_mutex);
    shrdvar*=5;
    printf("multiplied by 5 shared var is:%d\n",shrdvar);
    pthread_mutex_unlock(&my_mutex);
}

void *thread_div(void *arg){
    pthread_mutex_lock(&my_mutex);
    shrdvar/=5;
    printf("divided by 5 shared var is:%d\n",shrdvar);
    pthread_mutex_unlock(&my_mutex);
}

int main(void){
    pthread_t tid,tid2;
    pthread_mutex_init(&my_mutex,NULL);

    int ret = pthread_create(&tid,NULL,thread_mul,NULL);
    int ret2 = pthread_create(&tid2,NULL,thread_div,NULL);

    pthread_join(tid,NULL);
    pthread_join(tid2,NULL);

    printf("shared variable is now:%d\n",shrdvar);
    return 0;
}