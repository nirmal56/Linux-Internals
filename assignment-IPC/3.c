/*
3.Write a program parent process writing to pipe and child reading toggled data from pipe,
and also analyse the data flow order from write end to read end.
*/
#include<stdio.h>
#include<unistd.h>
#include<string.h>

int fds[2];
char buf1[40] = "tHiS iS tHe DaTa To Be ToGlEd.\n";

void toggle(char *buf, int cnt)
{
    //this function will toggle caps to small letters.
    for (int i = 0; i < cnt; i++)
    {
        if ((buf[i] >= 'A') && (buf[i] <= 'Z'))
            buf[i] += 32;
        else if ((buf[i] >= 'a') && (buf[i] <= 'z'))
            buf[i] -= 32;
    }
}

void parent(){
    //parent will write buffer to pipe
    close(fds[0]);
    write(fds[1],buf1,40);
    for(int i=0;i<strlen(buf1);i++)
        printf("%c",buf1[i]);
    printf("end of parent\n");
}

void child(){
    //child wil; read buffer from pipe
    char buf[100];
    int n,i;
    close(fds[1]);
    n=read(fds[0],buf,100);
    toggle(buf,strlen(buf));
    printf("no of chars read = %d\n",n);
    for(i=0;i<n;i++)
        printf("%c",buf[i]);
    printf("end of child\n");
}

int main(){
    int pipeFD ,i;
    pid_t p;
    pipeFD = pipe(fds);
    if(pipeFD == -1){
        perror("pipe");
        exit(0);
    }
    p=fork();
    if(p==0){
        child();
    }
    else{
        parent();
    }
    return 0;
}