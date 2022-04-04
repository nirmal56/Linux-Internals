#include<signal.h>
#include<stdio.h>
#include<unistd.h>

void sighand(int signum){
    printf("i have to wake up him now\n");
}

int main(){
    signal(SIGALRM,sighand);
    alarm(5);
    while(1);
}