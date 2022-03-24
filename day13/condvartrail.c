#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

pthread_cond_t cond1 = PTHREAD_COND_INITIALIZER;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

int done=1;

void *foo(void *arg){
    char *str =(char*)arg;
    printf("thread called by:%s\n",str);
    pthread_mutex_lock(&lock);
    if(done==1){
        printf("waiting for condition variable cond1\n");
        pthread_cond_wait(&cond1,&lock);                ///unlockks
        printf("here\n");
    }
    else if (done ==2){
        printf("waiting for condition variable cond2\n");
        pthread_cond_wait(&cond1,&lock);                ///unlockks
        pthread_cond_signal(&cond1);
        printf("here2\n");
    }
    else{
        printf("waiting for condition variable cond3\n");
        pthread_cond_signal(&cond1);

    }
    pthread_mutex_unlock(&lock);
    printf("returning thread\n");
    return NULL;
}

int main(){
    pthread_t tid1,tid2,tid3;
    pthread_create(&tid1,NULL,foo,"thdone");

    sleep(1);
    done=2;
    pthread_create(&tid2,NULL,foo,"thdtwo");

    sleep(1);
    done=3;
    pthread_create(&tid3,NULL,foo,"thdthree");

    pthread_join(tid3,NULL);
    return 0;

}