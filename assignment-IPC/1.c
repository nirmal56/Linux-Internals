/*
1.write a program that creates a shared memory region and displays shared memory id 
and also print address at which shared area in this process starts from.
*/
#include<stdio.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<sys/ipc.h>

int main(){
    int *p;
    int myId;
    myId= shmget(10,300,IPC_CREAT|0644);

    if(myId<0){
        perror("shmget");
    }

    printf("shared memory Id=%d\n",myId);
    p=shmat(myId,0,0);
    printf("Address at which shared memory is present:%p\n",&p);
    return 0;
}