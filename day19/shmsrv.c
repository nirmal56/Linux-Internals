#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <string.h>

#define MY_KEY 199
#define SHM_SIZE 0x1000

void toggleCase(char *buf, int cnt);

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
    int semId, shmId;
    char *pShm; // shared memory creation call will returns the pointer to the allocated region so we created this
    struct sembuf smop;

    // create a semaphore set, containing two semaphores
    semId = semget(MY_KEY, 1, 0660 | IPC_CREAT);
    if (semId < 0)
    {
        printf("could not create semaphore\n");
        return (1);
    }
    else
    {
        printf("opened a semaphore ID is: %d\n", semId);
    }

    // set initial token count of both semaphores to zeroes
    semctl(semId, 0, SETVAL, 0); // 0 after semId means only 1st semaphore(we created 3 semaphores(0,1,2) and we are taking only with the ID=0)

    // create a shared memory segment
    shmId = shmget(MY_KEY, SHM_SIZE, 0660 | IPC_CREAT);
    if (shmId < 0)
    {
        printf("could not create shared segment\n");
        return (2);
    }

    pShm = shmat(shmId, NULL, 0);
    if (!pShm)
    {
        printf("could not attach shared memory segment\n");
        return (3);
    }

    while (1)
    { // while(1) in the server means server will wait untill the client will conncet.
        // server initiated and wait for a client connection. untill a client is connected to a server, server is set to be in blocking mode
        //  wait for a token from semaphore 0
        smop.sem_num = 0;
        smop.sem_op = -1;
        smop.sem_flg = 0;

        semop(semId, &smop, 1);

        // process the message available is shared memory(below section from line 64 to 67 is critical section[section to be locked])
        printf("got the semaphore\n");
        strcpy(pShm + 256, pShm);
        toggleCase(pShm + 256, strlen(pShm + 256));
        printf("processed the request message and placed response\n");

        // send token to semaphore 1
        smop.sem_num = 0;
        smop.sem_op = -1;
        smop.sem_flg = 0;

        semop(semId, &smop, 1);
    }
}

void toggleCase(char *buf, int cnt)
{
    int ii;

    for (int i = 0; i < cnt; i++)
    {
        if (buf[i] >= 'A' && buf[i] <= 'Z')
        {
            buf[i] += 0x20; // 32 bit upper to lower
        }
        else if (buf[i] >= 'a' && buf[i] <= 'z')
        {
            buf[i] -= 0x20; // 32 bit upper to lower
        }
    }
}