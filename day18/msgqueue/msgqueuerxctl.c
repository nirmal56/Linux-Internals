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
    printf("id:%d\n",id);
    printf("\ndata is : %s\n",v.data);

    printf("details of queue:\n");
    printf("no of msg in quqeue %hi\n",buff.msg_qnum);
    printf("no of byes:%d\n",buff.msg_cbytes);
    printf("max no of bytes in q %hi\n",buff.msg_qbytes);

    msgctl(id,IPC_RMID,NULL);
    return 0;
}