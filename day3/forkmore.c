#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

int main(){
    int pid1;

    printf("current process pid : %d\n",getpid());
    pid1=fork();
    
    if(pid1==0){
        sleep(5);
        printf("new child process pid : %d\n",getpid());
        printf("new child parent process pid : %d\n",getppid());
    }
    else{
        sleep(3);
        printf("parent process pid : %d\n",getpid());
        printf("parent's parent process pid : %d\n",getppid());
    }
    while(1);
    return 0;
}
