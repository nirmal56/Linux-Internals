/*
1.Test whether the process(exec() system call) that replaces old program data , will inherit the fds or not.
*/

#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
    //execeutable file named 2 is needed to run this program
    int fd;
    fd = execl("/home/nirmal/user/Linux-Internals/day5/assignment/3","" ,0);//dont forget to typr file name inpaths
    if(fd == -1)
        printf("error opening file");
    return 0;
}