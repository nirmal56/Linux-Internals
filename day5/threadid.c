#include<stdio.h>
#include<pthread.h>

void *thread1(void *arg){
   pid_t pid;
   pthread_t tid;
   pid=getpid();
   tid=pthread_self();
   printf("pid is:%u and tid is:%u",pid,tid);
    return 0;
}
int main(void){
    pthread_t t1;
    void *res;
    int ret = pthread_create(&t1,NULL,thread1,NULL);
    if(ret != 0 ){
        printf("not created\n");
    }
    else{
        printf("created\n");
    }
    sleep(2);//we can  use join also.
    exit (0);
    return 0;
}