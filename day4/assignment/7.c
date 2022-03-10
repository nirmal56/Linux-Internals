/*
write a program child executed (exec()) a new program while parent waits child task to complete.
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(){
    int pid;
    pid=fork();
    if(pid==0){
        int ret = execl("/home/nirmal/user/Linux-Internals/day4/assignment/3","./3",NULL);
    }
    else{
        wait(0);
        printf("parent running");
    }
}