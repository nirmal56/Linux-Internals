/*
1.Test whether the process(exec() system call) that replaces old program data , will inherit the fds or not.
*/

#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
    //execeutable file named 2 is needed to run this program
     execl("/home/nirmal/user/Linux-Internals/day4/assignment/2","",0);//dont forget to typr file name inpaths
}