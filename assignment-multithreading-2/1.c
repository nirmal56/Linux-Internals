/*1. Write a pthread application where main task terminated but pending pthreads task still execute.*/
#include<stdio.h>
#include<pthread.h>
#include<string.h>

void *thread1(void *arg){
    char *s = (char *)arg;
    printf("%s\n",s);
    return (void*)strlen(s);
    return 0;
}
int main(void){
    pthread_t t1;
    void *res;
    int ret = pthread_create(&t1,NULL,thread1,"\nthread applied\n");
    printf("message from main:\n");
    printf("thread returned:%ld",pthread_self());
    pthread_exit(NULL);//null and 0 both will do here
    printf("this will not be executed as code is terminated\n");
    return 0;
}