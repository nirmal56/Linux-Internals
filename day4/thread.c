#include<pthread.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>

pthread_t tid,tid2;

void *thread1(void *arg){
    for(int i=0;i<500;i++)
    printf("thread 1 executing\n");
    return NULL;
}
void *thread2(void *arg){
    for(int i=0;i<500;i++)
    printf("thread 2 executing\n");
    return NULL;
}
int main(void){
    getchar();
    int ret = pthread_create(&tid,NULL,thread1,NULL);
    int ret2 = pthread_create(&tid2,NULL,thread2,NULL);
    getchar();
    if(ret || ret2){
        printf("cant creat\n");
    }
    else{
        printf("created\n");
        pthread_join(tid,NULL);
        pthread_join(tid2,NULL);
    }
}