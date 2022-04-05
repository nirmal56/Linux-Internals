#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>

static void signalhandler(int signo){
    if(signo == SIGINT)
        printf("caught sigint!");
    else if((signo == SIGALRM))
        printf("caught sigalarm!");
    else{ 
        printf("caught sigabort!");
        fprintf(stderr,"unecxpected eror siganl!\n");
        exit(EXIT_FAILURE);
    }
    exit(EXIT_FAILURE);
}

int main(){
    if(signal (SIGINT,signalhandler)  ==  SIG_ERR){
        fprintf(stderr,"cann't handle sigint!");
        exit(EXIT_FAILURE);
    }
    if(signal (SIGALRM,signalhandler)  ==  SIG_ERR){
        fprintf(stderr,"cann't handle siterm!");
        exit(EXIT_FAILURE);
    }
    alarm(4);
    if(signal (SIGABRT,SIG_DFL)  ==  SIG_ERR){
        fprintf(stderr,"cann't reser sigprof!!");
        exit(EXIT_FAILURE);
    }
    abort();
     if(signal (SIGABRT,SIG_IGN)  ==  SIG_ERR){
        fprintf(stderr,"cann't ignore sighup!");
        exit(EXIT_FAILURE);
    }
    for(;;)
        pause();
    
}