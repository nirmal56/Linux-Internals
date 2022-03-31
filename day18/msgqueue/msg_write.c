#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>

int main(){
    int qid;
    struct msqid_ds buf;
    qid=msgget(32,IPC_CREAT|0644);
    printf("qid = %d\n",qid);

    msgctl(qid,IPC_STAT,&buf);
    printf("details of queue:\n");
    printf("no of msg in quqeue %hi\n",buf.msg_qnum);
    printf("no of byes:%d\n",buf.msg_cbytes);
    printf("max no of bytes in q %hi\n",buf.msg_qbytes);
    return 0;
}