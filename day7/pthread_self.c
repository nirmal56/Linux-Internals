#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/mman.h>

struct my_thread{
    int threadid;
    char msg[100];
};

void * printhello(void *threadobj){
    pthread_t threadid;
    struct my_thread *t1;
    t1= (struct my_thread *)threadobj;
    threadid=pthread_self();
    printf("\nthread id : %u",threadid);
    printf("\n %d thread msg : %s\n",t1->threadid,t1->msg);
    
}

int main(){
    pthread_t thread2,thread3,threadid,thread4;
    int rc;
    struct my_thread t2,t3,t4;
    t4.threadid=4;
    strcpy(t4.msg,"i am thrwead 4");
    t4.threadid=2;
    strcpy(t2.msg,"i am thrwead 2");
    t4.threadid=3;
    strcpy(t3.msg,"i am thrwead 3");

    threadid = pthread_self();
    printf("\n main thread id:%u ",threadid);
    
    pthread_create(&thread4,NULL,printhello,(void*)&t4);
    pthread_create(&thread2,NULL,printhello,(void*)&t2);
    pthread_create(&thread3,NULL,printhello,(void*)&t3);
    printf("\n exititng main\n");
    pthread_exit(NULL);



}