/*3. Write a pthread program that implements simple initialization code.*/
#include<pthread.h>
#include<stdio.h>

pthread_once_t once =PTHREAD_ONCE_INIT;

void *myinit(){
    int i=0;
    printf("INIT function initialized %d times\n",++i);
}

void *threadfun(void *i){
    printf("\nthread no:%d\n",(int *)i);
    pthread_once(&once,(void*)myinit);
    printf("\nexiting my thread:%d\n",(int*)i);
}

int main(){
    pthread_t tid;
    pthread_create(&tid,NULL,threadfun,(void*)1);
    pthread_create(&tid,NULL,threadfun,(void*)2);
    pthread_create(&tid,NULL,threadfun,(void*)3);
    pthread_create(&tid,NULL,threadfun,(void*)4);
    printf("exiting main\n");
    pthread_exit(0);

}