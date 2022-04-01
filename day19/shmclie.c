#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <string.h>

#define MY_KEY 199
#define SHM_SIZE 0x1000
#define MSG_LEN 256
#define RESP_MSG_START 256

int main()
{
    int semId, shmId;
    char *pShm; // shared memory creation call will returns the pointer to the allocated region so we created this
    struct sembuf smop;

    // create a semaphore set, containing two semaphores
    semId = semget(MY_KEY, 1, 0660);
    if (semId < 0)
    {
        printf("could not create semaphore\n");
        return (1);
    }
    else
    {
        printf("opened a semaphore ID is: %d\n", semId);
    }

    // create a shared memory segment
    shmId = shmget(MY_KEY, SHM_SIZE, 0660);
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
    {
        printf("client: enter some request message to send to the server: \n");
        fgets(pShm, MSG_LEN, stdin);
        smop.sem_num = 0;
        smop.sem_op = 1;
        smop.sem_flg = 0;

        semop(semId, &smop, 1);

        // send token to semaphore 1
        smop.sem_num = 1;
        smop.sem_op = -1;
        smop.sem_flg = 0;

        semop(semId, &smop, 1);
        puts(pShm + RESP_MSG_START);
    }
}