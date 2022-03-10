/*
3. A program that replaces old progra, with vim editor program and open new text file.
*/
#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
    printf("thid will open txt1.txt file\n");
    int ret = execl("/usr/bin/vim","vim","txt1.txt",NULL);
    if(ret == -1){
        printf("error\n");
    }
}