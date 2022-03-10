#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main(){

printf("[one]\n");
     execl("/home/nirmal/user/Linux-Internals/day4/cmdlineexec","./cmdlineexec","kernal ","prog",0);//dont forget to typr file name inpaths


    printf("\n");
}