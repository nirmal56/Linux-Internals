#include<stdio.h>
#include<pthread.h>

void *my(void *i){
    printf("\n iam in %d thread\n",(int *)i);
}

int main(){
    pthread_t tid;
    struct sched_param para;
    int priority,policy,ret;

    ret=pthread_getschedparam(pthread_self(),&policy,&para);

    if(ret != 0)
        perror("getschedulepara");

        printf("\n----------------------Main thread---------------------------\n");
        printf("policy :%d\t priority:%d\n",policy,para.sched_priority);

        policy = SCHED_FIFO;
        para.sched_priority =3;
        ret = pthread_setschedparam(pthread_self(),policy,&para);

        if(ret != 0){
            perror("getschedpara");
        }

        ret = pthread_getschedparam(pthread_self(),&policy,&para);  
        if(ret != 0){
            perror("getschedpara");
        }

        printf("\n----------------------Main thread---------------------------\n");
        printf("policy :%d\t priority:%d\n",policy,para.sched_priority);
    
}