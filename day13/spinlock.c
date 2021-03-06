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
    rc= pthread_spin_lock(&slock);
    printf("thrread unlocked he spin locK:\n");

    rc=pthread_spin_unlock(&slock);
    printf("thread compleeted\n");

    return NULL;
}
int main(){
    pthread_t tid1,tid2;
    int rc=0;
    if(pthread_spin_init(&slock,PTHREAD_PROCESS_PRIVATE)!=0)
        perror("init");
    
    printf("main get spin locK\n");
    rc=pthread_spin_lock(&slock);
    printf("main,create the spin ;lock the thread\n");
    rc=pthread_create(&tid1,NULL,spilock,(int*)1);


    printf("main, wait a bit holding the spin lock\n");
    sleep(5);

    printf("main, unlock the spin lock\n");
    rc=pthread_spin_unlock(&slock);
    if(rc==0)
        printf("\n main thread succesfully unlocked\n");
    else   
        printf("\n unsucessful");
    printf("mian , wait for a second thread to end\n");
    rc=pthread_join(tid1,NULL);
    printf("main ended\n");


    return 0;

}