#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main(){

    pid_t pid1; //data tpye for pid;

    // if commented to get the -1 as the error as no child will present so wait will should throw an error

    // pid1=fork();
    // if(pid1==0){
    //     sleep(5);
    //     printf("child with 5 sec delay child pro pid=:%d\n",getpid());
    // }
    // else{
        int pid2;
        printf("parent pro pid:%d\n",getpid());
        pid2=wait(0);       //on return pid of terminated normally
        printf("parent saying child %d exited normlally\n",pid2);
        printf("parent process pid=%d",getpid());
    // }

}