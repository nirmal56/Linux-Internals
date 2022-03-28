/*5.Write a program that implements threads synchronization using pthread spinlock techniques.*/
#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

static pthread_spinlock_t spinlock;
volatile int slock;

void *spilock(void *arg){
    printf("Entered thread %d, getting spinlock\n",(int*)arg);
    printf("thread compleeted\n");

    return NULL;
}
int main(){
    pthread_t tid1,tid2;
    int rc=0;
    if(pthread_spin_init(&slock,PTHREAD_PROCESS_PRIVATE)!=0)
        perror("init");
    
    printf("main get spin lock\n");
    rc=pthread_spin_lock(&slock);

    printf("lock in spinlock mainnbody\n");
    rc=pthread_create(&tid1,NULL,spilock,(int*)1);

    printf("in waiting state\n");
    pthread_join(tid1,NULL);

    printf("unlock in spin lock main body\n");
    rc=pthread_spin_unlock(&slock);
    
    if(rc==0)
        printf("\nmain spinlock succesfully unlocked\n");
    else   
        printf("\nunsucessful unlock operation\n");
    printf("main ended\n");

    return 0;
}