#include<stdio.h>
#include<signal.h>


void sighand(int signum){
    printf("interrupt signak recieved\n");
    signal(SIGINT,SIG_DFL);//
}

int main(){
    int i;
    signal(SIGINT,sighand);
    for(i=0;;i++){
        printf("%d\n",i);
        sleep(1);
    }
}