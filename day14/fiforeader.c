#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
    char s[20];
    int fd;
    mkfifo("myfifo",0644);
    perror("mkfifo");
    printf("beforw open()\n");
    fd = open("myfifo",O_RDONLY);
    read(fd,s,sizeof(s));
    printf("data:%s\n",s);
    return 0;
}