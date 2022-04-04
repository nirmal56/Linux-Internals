#include<signal.h>
#include<stdio.h>
#include<unistd.h>

void sighand(int signum){
    printf("%d\n",signum);

    if(signum == SIGINT){
        printf("recieved\n");
    }
}

int main(){
    signal(SIGINT,sighand);
    alarm(5);
    while(1);
}