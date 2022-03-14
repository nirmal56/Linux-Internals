#include<pthread.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>

static pthread_spinlock_t spinlock;
volatile int slock;

void *spilock(void *arg){
    int     rc;
    int     count=0;
    printf("Entered thread %d, getting spinlock\n",(int*)arg);
   
    printf("thrread unlocked he spin locK:\n");

    printf("thread compleeted\n");

    return NULL;
}
int main(){
    pthread_t tid1,tid2;
    int rc=0;
    printf("main,create the spin ;lock the thread\n");
    rc=pthread_create(&tid1,NULL,spilock,(int*)1);

    pthread_exit(NULL);
    printf("main ended\n");


    return 0;

}