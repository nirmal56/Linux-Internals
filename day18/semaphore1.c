#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>

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
int sem_id;

int main(){
    int i,j;
    sem_id= semget((key_t)1234,1,0666||IPC_CREAT);

    
    for (int i=0;i<=10;i++){
        getsemaphore();
        printf("\n%d got the semaphore\n",getpid());
        for(int j=0;j<3;j++){
            sleep(1);
            printf("\a");
        }
        printf("\n%d release the semaphore\n",getpid());
        getrelease();
        sleep(1);
    }
    
}
int getsemaphore(void){
    sem_op.sem_num=0;
    sem_op.sem_op=-1;
    sem_op.sem_flg=SEM_UNDO;

    if(semop(sem_id,&sem_op,1)<0){
        printf("failed\n");
        return -1;
    }   

}

int getrelease(void){
    sem_op.sem_num=0;
    sem_op.sem_op=1;
    sem_op.sem_flg=SEM_UNDO;

    if(semop(sem_id,&sem_op,1)<0){
        printf("failed\n");
        return -1;
    }   
}