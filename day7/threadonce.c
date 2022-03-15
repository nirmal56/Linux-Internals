#include<pthread.h>
#include<stdio.h>

pthread_once_t once =PTHREAD_ONCE_INIT;

void *myinit(){
    printf("\n in init function\n");
}

void *mythread(void *i){
    printf("\n i am in mythread:%d\n",(int *)i);
    pthread_once(&once,(void*)myinit);
    printf("\n exit from my thread:%d\n",(int*)i);
}

int main(){
    pthread_t thread,thread1,thread2;
    pthread_create(&thread,NULL,mythread,(void*)1);
    pthread_create(&thread,NULL,mythread,(void*)2);
    pthread_create(&thread,NULL,mythread,(void*)3);
    printf("exiting main\n");
    pthread_exit(0);

}