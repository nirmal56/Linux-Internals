/*4.write a program, which get and set pthread scheduling policy and priority.*/
#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/mman.h>
//set inherit. 
void mythread(void * para){
    sleep(3);
    return 0;
}

int main(int argc,int argv[]){
    pthread_attr_t attr;
    pthread_t id;
    int err,info;

    pthread_attr_init(&attr);

    pthread_attr_getinheritsched(&attr,&info);
    switch(info){
        case PTHREAD_INHERIT_SCHED:
            printf("\nINHERIT\n");
            break;
        case PTHREAD_EXPLICIT_SCHED:
            printf("\nEXPLICIT\n");
            break;
    }

    pthread_attr_setinheritsched(&attr,PTHREAD_EXPLICIT_SCHED);

    pthread_attr_getinheritsched(&attr,&info);
        switch(info){
        case PTHREAD_INHERIT_SCHED:
            printf("\nINHERIT\n");
            break;
        case PTHREAD_EXPLICIT_SCHED:
            printf("\nEXPLICIT\n");
            break;
    }

    pthread_create(&id,&attr,mythread,NULL);
    return 0;
}