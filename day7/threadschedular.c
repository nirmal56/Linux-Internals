#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/mman.h>

void proc(void * para){
    sleep(3);
    return 0;
}
//gertinherit
int main(int argc,int argv[]){
    pthread_attr_t attr;
    pthread_t id;
    int err,info;

    pthread_attr_init(&attr);
    pthread_attr_getinheritsched(&attr,&info);

    switch(info){
        case PTHREAD_INHERIT_SCHED:
            printf("\nsched\n");
            break;
        case PTHREAD_EXPLICIT_SCHED:
            printf("\nExplicit\n");
            break;
    }

    pthread_create(&id,&attr,proc,NULL);
    return 0;
}