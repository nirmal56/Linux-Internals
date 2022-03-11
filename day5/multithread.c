#include<pthread.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
int fd;
void *thread1(void *p){
    char *str,buf[100];
    int n,pid;

    str=(char*)p;
    pid=getpid();
    printf("\n%s \t started now \t for process%d\n\n",str,pid);

    do{
        n=read(fd,buf,100);
        printf("\n%s: \t Read: \t %d\n\n",str,pid);
        printf("\n------------------------------\n");
        write(1,buf,n);
        sleep(3);
    }
    while(n);
    printf("%s \t finished \t for process: %d\n\n",str,pid);
}
int main(void){
    pthread_t t1,t2;
    fd=open("/etc/passwd",O_RDONLY);
    printf("file opened eith fiel id:%d",fd);

    pthread_create(&t1,NULL,thread1,"thread one");
    pthread_create(&t2,NULL,thread1,"thread two");
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
        
}