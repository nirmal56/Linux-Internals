#include<pthread.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>

void *proc(void * para){
    sleep(2);
    return 0;
}

int main(){
    pthread_attr_t  attr;
    pthread_t       id;
    void            *stk;
    size_t          siz;
    int             err;

    size_t my_stksize = 0x2000000;
    void * my_stack;

    pthread_attr_init(&attr); 
    pthread_attr_getstacksize(&attr,&siz);
    pthread_attr_getstackaddr(&attr,&stk);

    printf("default addr = %08x default size=%d\n",stk,siz);
    my_stack = (void*)malloc(my_stksize);
    pthread_attr_setstack(&attr,my_stack,my_stksize);
    pthread_create(&id, &attr, proc, NULL);
    pthread_attr_getstack(&attr,&stk,&siz);
    printf("newly defined stack :adr=%08x and size =%d\n",stk,siz);
    sleep(3);
}