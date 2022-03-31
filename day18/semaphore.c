#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<unistd.h>
#include<stdlib.h>

union semnum{
    int val;
    struct sid_ds;
    unsigned short * array;
    struct seminfo *_buf;
};   


int getrelease(void);
int getsemaphore(void);

struct sembuf sem_op;
union semnum sem_union;
int sid;

int main(){
    int id;

    int i;
    sleep(3);
    sid = semget((key_t)10,1,0666|IPC_CREAT);
    printf("\nsemaphore id:%d\n",sid);
    sem_union.val=1;

    if (semctl(sid,0,SETVAL,sem_union)<0)
        printf("error\n");

    for (int i=0;i<=5;i++){
        getsemaphore();
        printf("\n%d got the semaphore\n",getpid());
        sleep(1);
        printf("\n%d release the semaphore\n",getpid());
        getrelease();
        sleep(1);
    }

    if (semctl(sid,0,IPC_RMID,sem_union)<0)
        printf("\nfailed to delete the semaphore\n");
    else    
        printf("\nsemaphore deleted\n");
    
}
int getsemaphore(void){
    sem_op.sem_num=0;
    sem_op.sem_op=-1;
    sem_op.sem_flg=SEM_UNDO;

    if(semop(sid,&sem_op,1)<0){
        printf("failed\n");
        return -1;
    }   

}

int getrelease(void){
    sem_op.sem_num=0;
    sem_op.sem_op=1;
    sem_op.sem_flg=SEM_UNDO;

    if(semop(sid,&sem_op,1)<0){
        printf("failed\n");
        return -1;
    }   
}