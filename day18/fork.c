#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>

void myfun(int n){
    for(int i=0;i<n;i++) 
    {
        if(fork() == 0)
        {
            printf(" pid %d from parent pid %d\n",getpid(),getppid());
            printf("%d process with id:%d",i,getpid());
            exit(0);
        }
    }
    // for(int i=0;i<n;i++) 
    // wait(NULL);
}

int main(){
    myfun(10);
}