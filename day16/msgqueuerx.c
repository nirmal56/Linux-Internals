#include<stdio.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/bitypes.h>>


struct msgbuf{
    long mtype;
    char data[512];
};

int main(int argc,int *argv[]){
    struct msgbuf v;
    int id;

    if(argc != 2){
        printf("usage:./mqrxtype\n");
        printf("Example:mq_rx 5\n");
        return 0;
    }
    id = msgget(55,IPC_CREAT|0644);
    if(id<0){
        perror("msgget");
    }
    msgrcv(id,&v,sizeof(v),atoi(argv[1]),0);
    printf("data is : %s",v.data);
    return 0;
}