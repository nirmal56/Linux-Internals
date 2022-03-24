/*
3. Write a program that changes the default properties of newly created posix
threads.(ex: to change default pthread stack size )
*/
#include<pthread.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>

void *proc(void * para){
    printf("in the thread\n");
}

int main(){
    pthread_attr_t  attr;
    pthread_t id;
    void *stkaddr;
    size_t siz;
    int err;

    size_t my_stksize = 0x3000000;
    void * my_stack;

    pthread_attr_init(&attr); 
    pthread_attr_getstacksize(&attr,&siz);
    pthread_attr_getstackaddr(&attr,&stkaddr);
    printf("default addr = %08x default size=%d\n",stkaddr,siz);

    my_stack = (void*)malloc(my_stksize);
    pthread_attr_setstack(&attr,my_stack,my_stksize);

    pthread_create(&id, &attr, proc, NULL);

    pthread_attr_getstack(&attr,&stkaddr,&siz);
    printf("newly defined stack is now:adr=%08x and size =%d\n",stkaddr,siz);
    pthread_join(id,NULL);
    
    return 0;
}