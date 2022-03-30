#include<stdio.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/bitypes.h>
#include<sys/msg.h>

struct msgbuf{
    long mtype;
    char data[512];
};

int main(int argc,int *argv[]){
    struct msgbuf v;
    struct msqid_ds buff;
    int id;

    id = msgget(55,IPC_CREAT|0644);
    printf("id=%d\n",id);

    v.mtype=atoi(argv[1]);
    strcpy(v.data,argv[2]);
    msgsnd(id,&v,strlen(v.data)+1,0);

    msgctl(id,IPC_STAT,&buff);
    printf("details of queue:\n");
    printf("no of msg in quqeue %hi\n",buff.msg_qnum);
    printf("no of byes:%d\n",buff.msg_cbytes);
    printf("max no of bytes in q %hi\n",buff.msg_qbytes);
    return 0;
}