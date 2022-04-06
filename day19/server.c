#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <string.h>
#define MY_KEY 199
#define SHM_SIZE 0x1000

void toggleCase(char *buf, int cnt)
{
    int ii;
    for (ii = 0; ii < cnt; ii++)
    {
        if ((buf[ii] >= 'A') && (buf[ii] <= 'Z'))
            buf[ii] += 0x20;
        else if ((buf[ii] >= 'a') && (buf[ii] <= 'z'))
            buf[ii] -= 0x20;
    }
}
union semun
{
    int val;
    struct semid_ds *buf;
    unsigned short *array;
    struct seminfo *__buf;
};
union semun sem_union;
int main()
{
    int semid, shmid;
    char *pshm;
    struct sembuf smop;
    semid = semget(MY_KEY, 1, 0660 | IPC_CREAT);
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
    shmid = shmget(MY_KEY, SHM_SIZE, 0660 | IPC_CREAT);
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
        smop.sem_num = 0;
        smop.sem_op = -1;
        smop.sem_flg = 0;

        semop(semid, &smop, 1); // critical section which is protected
        printf("got the semaphore");
        strcpy(pshm + 256, pshm);
        toggleCase(pshm + 256, strlen(pshm + 256));
        printf("processed the request message and placed response\n"); // critical section which is protected

        // send token to semaphore 1
        smop.sem_num = 1;
        smop.sem_op = 1;
        smop.sem_flg = 0;

        semop(semid, &smop, 1);
    }
}