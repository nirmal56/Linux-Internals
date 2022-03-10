#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main(){

    pid_t pid1; //data tpye for pid;

    pid1=fork();
    if(pid1==0){
        sleep(5);
        printf("child with 5 sec delay child pro pid=:%d",getpid());
    }
    else{
        int pid2;
        printf("parent pro pid:%d",getpid());
        pid2=wait();
        printf("parent saying child %d exited normlally\n",pid2);
        printf("parent process pid=%d",getpid());
    }

}