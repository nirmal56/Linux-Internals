/*
6. Write a program child executes(exec()) a new program , while parent waits for
child task to get complete.
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(){
    int pid;
    pid=fork();
    if(pid==0){
        //executable file named 2 is needed to run this program
        int ret = execl("/home/nirmal/user/Linux-Internals/day4/assignment/","./2",NULL);
    }
    else{
        wait(0);
        printf("parent running");
    }
}