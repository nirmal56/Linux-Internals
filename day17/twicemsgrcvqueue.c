#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/types.h>
// #include <sys/bitypes.h>

struct msgbuf
{
    long mtype;
    char data[10];
} msg;

int main()
{
    struct msgbuf msg1, msg2;
    int qid;
    int i;

    qid = msgget(32, IPC_CREAT | 0644);
    if (qid < 0)
    {
        perror("msgget");
    }
    i = msgrcv(qid, &msg1, sizeof(msg), 10, 0);
    printf("value of data1: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%c", msg1.data[i]);
    }
    printf("\n");

    i = msgrcv(qid, &msg2, sizeof(msg), 20, 0);
    printf("\nvalue of data2: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%c", msg2.data[i]);
    }
    printf("\n");
    return 0;
}