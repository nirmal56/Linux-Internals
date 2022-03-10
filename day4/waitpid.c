#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main(){ 
    int status;

    pid_t pid1; //data tpye for pid;
        printf("parent pro pid=:%d\n",getpid());

    pid1=fork();
    if(pid1==0){
        sleep(2);
        printf("child  child pro pid=:%d\n",getpid());
        exit(0);
    }
printf("parent reporting exit of child with pid:%d\n",waitpid(pid1,&status,0));

}