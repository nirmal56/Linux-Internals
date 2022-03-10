#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
    int pid1;

    printf("current process pid : %d\n",getpid());
    pid1=fork();
    
    if(pid1==0){
      execl("/bin/ls","ls","-lh",0);
    }
    else{
       //execl("/bin/ls","ls","-lh",0);
    }
    exit(0);
    return 0;
}
