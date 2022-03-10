#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

void callback1(void){
    printf("calback1\n");
}
void callback2(void){
    printf("calback2\n");
}
void callback3(void){
    printf("calback3\n");
}

int main(){
    printf("calling back 1:\n");
    atexit(callback1);
    printf("calling back 2:\n");
    atexit(callback2);
    printf("calling back 3:\n");
    atexit(callback3);
    _exit(0);//will not callback prev functoins
    exit(0);//will callback prev functions
}