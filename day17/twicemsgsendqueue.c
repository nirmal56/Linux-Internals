#include<stdio.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/bitypes.h>


struct msgbuf{
    long mtype;
    char data[10];
}msg;

int main(){
    struct msgbuf msg1,msg2;
    int id;
    int i;

    id = msgget(32,IPC_CREAT|0644);
    
    msg1.mtype=10;
    for(int i=0;i<10;i++){
        msg1.data[i]='a';
    }

    msg2.mtype=20;
    for(int i=0;i<10;i++){
        msg2.data[i]='b';
    }

    i=msgsnd(id,&msg1,sizeof(msg),0);
    printf("return value of msgsend of As is:%d\n",i);
    i=msgsnd(id,&msg2,sizeof(msg),0);
    printf("return value of msgsend of Bs is:%d\n",i);
    return 0;
}