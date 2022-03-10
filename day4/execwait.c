#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
//prog which has 4 exec and wait according to parent child gcc
int main(){

    int pid1;

    pid1=fork();
    
    if(pid1==0){
        execl("/bin/ls","ls","-lh",0);
    }
    else{
        wait(0);
        printf("child pro done");
    }
      
    exit(0);
}
