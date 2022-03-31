/*2.Write a program where a structure of information passed to pthread task function, and display structure of information.*/
#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

pthread_t tid;
struct mythread{
    int thread_id;
    char msg[30];    
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
    int rc;
    struct mythread  t1;

    t1.thread_id=1;
    strcpy(t1.msg,"\nMessage is from thread 1\n");
    int ret1 = pthread_create(&tid,NULL,thread,(void*)&t1);

    printf("\nmessage form main:\n");
    
    pthread_join(tid,NULL);
    return 0;
}