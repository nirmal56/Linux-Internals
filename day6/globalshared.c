#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

int sharedvar=5;

void *thread_inc(void *arg){
    sharedvar++;
    printf("after increment:%d\n",sharedvar);
}
void *thread_dec(void *arg){
    sharedvar--;
    printf("after decrement:%d\n",sharedvar);
}
int main(void){
    pthread_t tid,tid2;
    int ret = pthread_create(&tid,NULL,thread_inc,NULL);
    int ret2 = pthread_create(&tid2,NULL,thread_dec,NULL);

    pthread_join(tid,NULL);
    pthread_join(tid2,NULL);

    printf("shared variable:%d\n",sharedvar);
    return 0;
}