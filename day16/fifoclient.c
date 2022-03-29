#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
    printf("client process writing\n");
    char clientmsg[] = "linux kernal programming\n";
    int fd = open("cli_ser_fifo",O_WRONLY);
    if(fd == -1){
        perror("can't open fifo\n");
        return EXIT_FAILURE;
    }
    write(fd,clientmsg,strlen(clientmsg));
    return 0;
}