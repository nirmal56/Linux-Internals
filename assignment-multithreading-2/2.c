/*2.Write a program where a structure of information passed to pthread task function, and display structure of information.*/
#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct mythread{
    int thread_id;
    char msg[20];    
};

static void *thread(void *thrdobj){
    pthread_t thredid;
    struct mythread *t1;
    t1= (struct mythread *) thrdobj;
    thredid=pthread_self();
    printf("\nthread id is:%u",thredid);
    printf("\n%d thread msg %s", t1->thread_id,t1->msg);
    return 0;
}

int main(void){
    pthread_t tid1,tid2,tid3;
    int rc;
    struct mythread  t1,t2,t3;

    t1.thread_id=1;
    strcpy(t1.msg,"\nfrom thread 1\n");
    t2.thread_id=2;
    strcpy(t2.msg,"\nfrom thread 2\n");
    t3.thread_id=3;
    strcpy(t3.msg,"\nfrom thread 3\n");

    int ret1 = pthread_create(&tid1,NULL,thread,(void*)&t1);
    int ret2 = pthread_create(&tid2,NULL,thread,(void*)&t2);
    int ret3 = pthread_create(&tid3,NULL,thread,(void*)&t3);

    printf("\nmessage form main:\n");
    
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    pthread_join(tid3,NULL);
    return 0;
}