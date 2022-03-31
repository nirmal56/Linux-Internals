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
    fd = open("myfifo",O_WRONLY);
    printf("Enter data\n");
    scanf("%s", s);
    write(fd,s,strlen(s)+1);
    return 0;
}