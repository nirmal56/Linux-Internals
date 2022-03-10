/*
test whether the process (exec() system call) that replaces old program data, will inherit the fd's or not.
*/
#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
     execl("/home/nirmal/user/Linux-Internals/day4/assignment/3","",0);//dont forget to typr file name inpaths
}
///a.out 