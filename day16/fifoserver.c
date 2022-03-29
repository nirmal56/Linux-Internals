#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<string.h>
#include<unistd.h>


int main(){
    printf("server is listenning\n");

    int code = mkfifo("cli_ser_fifo",0763);

    if(code == -1){
        perror("mkfifo returned an error- file may exist.\n");
    }

    int fd= open("cli_ser_fifo",O_RDONLY);
    if(fd == -1){
        perror("can't open the file to be read\n");
    }

    printf("fifo opened");

    char serverrcv[100];
    memset(serverrcv,0,100);
    int res;
    char len;

    while(1){
        res = read(fd,&len,1);
        if(res == 0){
            break;
        }
        read (fd,serverrcv,len);
        printf("server recieved:%s\n",serverrcv);
    }
    close(fd);
    return 0;

}