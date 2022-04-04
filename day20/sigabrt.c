#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>

void abort_handler(int);

int main(){
    if(signal(SIGABRT,abort_handler) == SIG_ERR){
        fprintf(stderr,"coudlnot set sifnal handler\n");
    }

    abort();

    exit(0);

}

void abort_handler(int i){
    fprintf(stderr,"caught abort\n");
    exit(1);
}