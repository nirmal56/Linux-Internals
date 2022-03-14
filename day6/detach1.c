#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#define NUM_THREADS 3
int i=0;

void *myfun(void *null){
    i++;
    int result=0;
    result += (i*1000);
    printf("result=%d\n",result);
    pthread_exit(NULL);
}

int main(){
    pthread_t thread[NUM_THREADS];
    pthread_attr_t attr;
    int rc,t,status,detach_state;

    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);

    for(int i=0;i<NUM_THREADS;i++){
        printf("creating threaD:%d\n",i);
        pthread_create(&thread[i],&attr,myfun,NULL);
    }
    pthread_attr_getdetachstate(&attr,&detach_state);
    printf("\n detacehd state:%d\n",(int*)detach_state);
    
    printf("\nExting main\n");
    pthread_exit(NULL);
    return 0;
}