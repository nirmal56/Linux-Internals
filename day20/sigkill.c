#include<stdio.h>
#include<signal.h>

void sighand(int signum){
    printf("inside intel\n");
}
int main(){
    pid_t pid;
    signal(SIGUSR1,sighand);
    printf("inside main function\n");
    pid= getpid();

    kill(pid,SIGUSR1);
    printf("ended main function\n");
    // return 0;
}