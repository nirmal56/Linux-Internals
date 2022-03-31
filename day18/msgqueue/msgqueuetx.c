#include<stdio.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/bitypes.h>

struct msgbuf{
    long mtype;
    char data[512];
};

int main(int argc,int *argv[]){
    struct msgbuf v;
    int id;
    id = msgget(55,IPC_CREAT|0644);
    printf("id=%d\n",id);
    v.mtype=atoi(argv[1]);
    strcpy(v.data,argv[2]);
    msgsnd(id,&v,strlen(v.data)+1,0);
    return 0;
}