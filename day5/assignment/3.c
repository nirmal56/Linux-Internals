/*
3. A program that replaces old program with new program data and is expected to display the currently running processes in a 
hierarchical tree format.
*/

#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
    // int ret = execl("/home/nirmal/user/Linux-Internals/day5/assignment/1.c","vim","1.c",NULL);
    // if(ret == -1){
    //     printf("error\n");
    // }

    int retu = execl("pstree",NULL);
}