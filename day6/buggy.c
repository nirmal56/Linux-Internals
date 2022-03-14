#include<pthread.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>

void buggy(){
    int *intptr;
    int i;
    intptr= (int *)malloc(sizeof(int)*5);
    printf("mallock chekcing :addr = %08x and size%d\n",intptr, sizeof(int)*5);

    for(int i=0;i<8;i++){
        *intptr=100;
        printf("value at ptr intptr:%d\n",(*intptr));
        intptr++;
    }
}
int main(void){
    buggy();
    return 0;
}