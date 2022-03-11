/*
write a program parent process wait untill, while child process open a file and read file data into empty buffer
*/

#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
// #include<String>

int main(){
    int pid,fd;
    int i;
    pid = fork();
    char wbuf[30]="a file that will be written.";
    char rbuf[30];
    if (pid == 0){
        fd=open("file3.txt", O_CREAT | O_RDWR, 0777);
        if((i=write(fd,wbuf,30))<0){
                printf("file wruttn.\n");
        }
   
        printf("read data is:%s\n",rbuf);
        write(1,buf,n);

    }

    else{
        wait(0);
        printf("parent running");
    }
}