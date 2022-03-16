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
        printf("\n1st child is:%d\n",getpid());
    }
    else{
        printf("\n2nd child is:%d\n",getpid());
        pid2=fork();
        if(pid2==0){
            // execl("/usr/bin/pstree","pstree",NULL);
            printf("successfully run execl() for child process 1\n");
        } else{
            // wait(0);
            printf("failed to run execl() for child process 1\n");
        }
        wait(0);
        pid3=fork();
        if(pid3==0){
            // execl("/usr/bin/vim","vim","txt3.txt",NULL);
            printf("successfully run execl() for child process 2\n");
        } else{
            // wait(0);
            printf("failed to run execl() for child process 2\n");
        }
    }
    exit(0);
    return 0;
}