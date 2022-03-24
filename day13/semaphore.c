#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>

int sharedvar=5;
sem_t my_sem;

void *thread_inc(void *arg){
    sem_wait(&my_sem);
    sharedvar++;
    printf("1\n");
    sem_post(&my_sem);
}
void *thread_dec(void *arg){
    sem_wait(&my_sem);
    sharedvar--;
    printf("-1\n");
    sem_post(&my_sem);
}
int main(void){
    pthread_t tid,tid2;
    sem_init(&my_sem,0,1);
    int ret = pthread_create(&tid,NULL,thread_inc,NULL);
    int ret2 = pthread_create(&tid2,NULL,thread_dec,NULL);

    pthread_join(tid,NULL);
    pthread_join(tid2,NULL);

    printf("shared variable:%d\n",sharedvar);
    return 0;
}