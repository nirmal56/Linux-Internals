#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

int main()
{
    int pid1 = 1;
    int fd1;
    char buffer[30];

    pid1 = fork();

    if (pid1 == 0)
    {
        printf("this process is child process\n");
        fd1 = open("linux.txt", O_RDWR | O_RDONLY, 0); // to read the file
        printf("\n\n%d\n", fd1);
        read(fd1, buffer, 30);

        printf("inside reading file");
    }
    else
    {

        wait(0);
        printf("this process is parent process\n");
    }
    return 0;
}