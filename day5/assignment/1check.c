#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
    //execeutable file named 2 is needed to run this program
    int fd;
    fd = open("/home/nirmal/user/Linux-Internals/day5/assignment/1",O_RDONLY,777);//dont forget to typr file name inpaths
    printf("%d\n",fd);
    return 0;
}