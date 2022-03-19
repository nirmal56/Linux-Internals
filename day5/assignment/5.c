/*
5.Write a program parent process wait untill ,while child process open a file and read file
data into empty buffer.
*/
#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
int main(){
    int pid,fd;
    int i;
    pid = fork();
    char rbuf[50];
    if (pid == 0){
        fd=open("file3.txt", O_CREAT | O_RDWR, 0777);
        
        read(fd,rbuf,50);
        printf("read data is:%s\n",rbuf);
    }
    else{
        wait(0);
        printf("parent running\n");
    }
}