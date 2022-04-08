/*
2.write a program that uses msgctl() and prints number of messages,number of bytes in message queue and also 
get Maximum number of bytes in queue for already existing message queue and also remove message queue at the end.
*/
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<sys/bitypes.h>

struct mymsgbuff{
    long mtype;
    char data[512];
};

int main(int argc,int *argv[]){
    struct mymsgbuff v,v1;
    struct msqid_ds buff;
    int myid;

    myid = msgget(10,IPC_CREAT|0644);
    printf("id=%d\n",myid);

    v.mtype=atoi(argv[1]);
    strcpy(v.data,argv[2]);
    msgsnd(myid,&v,strlen(v.data)+1,0);

    msgctl(myid,IPC_STAT,&buff);
    printf("\n--------------details of queue-----------------\n");
    printf("\tno of msg in quqeue: %hi\n",buff.msg_qnum);
    printf("\tno of byes: %d\n",buff.__msg_cbytes);
    printf("\tmax no of bytes in queue is: %hi\n",buff.msg_qbytes);
    // msgctl(myid,IPC_RMID,NULL);
    // printf("\tmessage queue with id %d is removed\n",myid);
    // printf("-----------------------------------------------\n");

    v1.mtype=atoi(argv[3]);
    strcpy(v1.data,argv[4]);
    msgsnd(myid,&v1,strlen(v1.data)+1,0);

    msgctl(myid,IPC_STAT,&buff);
    printf("\n--------------details of queue-----------------\n");
    printf("\tno of msg in quqeue: %hi\n",buff.msg_qnum);
    printf("\tno of byes: %d\n",buff.__msg_cbytes);
    printf("\tmax no of bytes in queue is: %hi\n",buff.msg_qbytes);
    msgctl(myid,IPC_RMID,NULL);
    printf("\tmessage queue with id %d is removed\n",myid);
    printf("-----------------------------------------------\n");
    return 0;
}