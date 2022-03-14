#include<stdio.h>
#include<pthread.h>
 
static pthread_spinlock_t spinlock;
volatile int slock;

void *process(void *arg){
   pthread_detach(pthread_self());
   printf("sleeping\n");

   sleep(2);
   printf("woke up");

    return NULL;
}
int main(){
    pthread_t tid1,tid2;
    int rc=0;
   
    rc=pthread_create(&tid1,NULL,process,(int*)1);

    pthread_exit(NULL);
    printf("main ended\n");


    return 0;

}