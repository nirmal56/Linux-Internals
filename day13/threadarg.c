#include<pthread.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>

static void *thread1(void *arg){
    char *s = (char *)arg;
    printf("%s\n",s);
    return 0;
}
int main(void){
    pthread_t t1;
    void *res;
    int ret = pthread_create(&t1,NULL,thread1,"helllo thread");
    printf("message form main:");
    sleep(2);//we can  use join also.
    exit (0);
    return 0;
}