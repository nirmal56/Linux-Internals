#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <string.h>
#define my_key 199
#define shm_size 0x1000
#define msg_len 256
#define pesp_msg_stsrt 256



int main()
{
int semid, shmid;
char *pshm;
struct sembuf smop;
semid = semget(my_key, 1, 0660);
if (semid < 0)
{
printf("could not create semaphore\n");
return (1);
}
else
{
printf("open semaphore id id %d \n", semid);
}
// set initial token count of both semaphores to zeroes
semctl(semid, 0, SETVAL, 0);



// create a shared memory segment
shmid = shmget(my_key, shm_size, 0660 | IPC_CREAT);
if (shmid < 0)
{
printf("could not create shared segment\n");
return (2);
}



pshm = shmat(shmid, NULL, 0);
if (!pshm)
{
printf("could not attach shared memory segment\n");
return (3);
}
while (1) // server initiated and waits for client conection untill a client connected to server server said to be blocking call and server will wait here
{
printf("client: enter some request message to send to server\n");
fgets(pshm,msg_len,stdin);
smop.sem_num = 0;
smop.sem_op = 1;
smop.sem_flg = 0;

semop(semid, &smop, 1);
// strcpy(pshm + 256, pshm);
smop.sem_num = 1;
smop.sem_op = -1;
smop.sem_flg = 0;



semop(semid, &smop, 1);
puts(pshm+pesp_msg_stsrt);
}
}