#include<pthread.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
    int id;

void *print(void *threadid){
    printf("\nhello thread\n");
    sleep(6);
    id=pthread_self();
    while(1);
}

int main(){
    pthread_t thread;
    int rc,t=0;
    printf("creating thread\n");
    rc =pthread_create(&thread , NULL,print,NULL);
    printf("thread id:%u\t%u\n",thread,id);
    t=pthread_cancel(rc);
    if(t==0)
        printf("\n canceled thread\n");
    printf("thread id:%u\t%u\n",thread,id);
}