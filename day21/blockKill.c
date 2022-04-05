#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>

void printSiganlSet(sigset_t *set){
    const int siglist[] ={ SIGHUP, SIGINT, SIGQUIT,SIGKILL, SIGABRT,SIGFPE,SIGILL,SIGSEGV};
    const char *signames[] ={ "SIGHUP", "SIGINT", "SIGQUIT","SIGKILL", "SIGABRT","SIGFPE","SIGILL","SIGSEGV"};
    const int siglen=8;

    for(int i=0;i<siglen;i++){
        int ret =sigismember(set,siglist[i]);

        if(ret == -1){
            perror("sigismember");
            exit(EXIT_FAILURE);
        }

        else if(ret == 1){
            printf("signal is %s = %d is in the set\n",signames[i],siglist[i]);
        }

        else{
            printf("signal is %s = %d is not in the set\n",signames[i],siglist[i]);
        }

    }
}

int main(){
    sigset_t set;
    if(sigprocmask(0,NULL,&set) != 0){
        perror("sigpromask:");
        exit(EXIT_FAILURE);
    }
    
    printf("---initial siganl mask for this process---\n");
    printSiganlSet(&set);

    //#if 1

    if(sigaddset(&set,SIGINT) != 0){
        perror("sigaddset:");
        exit(EXIT_FAILURE);
    }
    if(sigprocmask(SIG_SETMASK,&set,NULL) != 0){
        perror("sigpromask:");
        exit(EXIT_FAILURE);
    }
    //now sigint 

    printf("---New siganl mask for this process---\n");
    printSiganlSet(&set);

    int secToSleep =28;
    printf(" trc ctrl +c killing this program with kill -kill %d .going to sllep for %d seconds.\n",getpid(),secToSleep);
    sleep(secToSleep);
    printf("sleep returned\n");
    printf("return all signals\n");
    sigfillset(&set);
    sigprocmask(SIG_SETMASK,&set,NULL);
    sleep(1);
    printf("exited normally\n");
    return 0;

}