/*
2.Write a program such that parent process create two child processes,such that each child executes a separate task.
*/
#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
    int pid1,pid2,pid3;
    printf("\nparent process is:%d\n",getpid());
    pid1=fork();
    if(pid1==0){
        printf("\nMain child is:%d\n",getpid());
    }
    else{
        pid2=fork();
        wait(0);
        if(pid2==0){
            printf("\n1st child is:%d\n",getpid());
            printf("successfully run execl() for child process 1\n");
        } 
        else{
            printf("failed to run execl() for child process 1\n");
        }
        wait(0);
        pid3=fork();
        if(pid3==0){
            printf("\n2nd child is:%d\n",getpid());
            printf("successfully run execl() for child process 2\n");
        } 
        else{
            printf("failed to run execl() for child process 2\n");
        }
    }
    exit(0);
    return 0;
}