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
        execl("/usr/bin/vim","vim","txt1.txt",NULL);
    }
    else{
        printf("\n2nd child is:%d\n",getpid());
        execl("/usr/bin/vim","vim","txt2.txt",NULL);
        pid2=fork();
        pid3=fork();
    }
    exit(0);
    return 0;
}