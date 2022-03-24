#include<pthread.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>s

struct mythread{
    int thread_id;
    char msg[20];    
};

static void *thread(void *thrdobj){
    pthread_t thredid;
    struct mythread *t1;
    t1= (struct mythread *) thrdobj;
    thredid=pthread_self();
    printf("\n thread id is:%u\n",thredid);
    printf("\n %d thread msg %s\n", t1->thread_id,t1->msg);
    return 0;
}

int main(void){
    pthread_t theread1,theread2,theread3;
    int rc;
    struct mythread  t1,t2,t3;

    t3.thread_id=3;
    strcpy(t3.msg,"from thread 3\n");
    t2.thread_id=2;
    strcpy(t2.msg,"from thread 2\n");
    t1.thread_id=1;
    strcpy(t1.msg,"from thread 1\n");

    int ret1 = pthread_create(&theread1,NULL,thread,(void*)&t1);
    int ret2 = pthread_create(&theread2,NULL,thread,(void*)&t2);
    int ret3 = pthread_create(&theread3,NULL,thread,(void*)&t3);
    printf("message form main:");
    sleep(2);
    exit (0);
    return 0;
}