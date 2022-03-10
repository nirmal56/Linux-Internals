#include<pthread.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>

pthread_t tid;

void *thread1(void *arg){
    printf("thread 1 executing\n");
    return NULL;
}

int main(void){
    int ret = pthread_create(&tid,NULL,thread1,NULL);
    if(ret){
        printf("cant creat\n");

    }
    else{
        
        printf("created\n");
        
        pthread_join(tid,NULL);
    }
}