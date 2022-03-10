/*
test whether the process (exec() system call) that replaces old program data, will inherit the fd's or not.
*/
#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
    int fd;
    fd=open("/home/nirmal/user/Linux-Internals/day4/assignment/2",O_RDONLY,0777);

    printf("%d",fd);
    
}
///a.out 