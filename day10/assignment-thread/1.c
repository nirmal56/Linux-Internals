/*
1.Write a multithreading program, where threads runs same shared golbal variable of
the process between them.
*/
#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

int shrvar=10;

void *thrd_inc(void *arg){
    shrvar++;
    printf("after increment value of shared variable is:%d\n",shrvar);
}
void *thrd_dec(void *arg){
    shrvar--;
    printf("after decrement value of shared variable is:%d\n",shrvar);
}
int main(void){
    pthread_t tid,tid2;
    int ret = pthread_create(&tid,NULL,thrd_inc,NULL);
    int ret2 = pthread_create(&tid2,NULL,thrd_dec,NULL);

    pthread_join(tid,NULL);
    pthread_join(tid2,NULL);

    printf("shared variable Now has value:%d\n",shrvar);
    return 0;
}