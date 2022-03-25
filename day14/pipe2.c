#include<stdio.h>
#include<unistd.h>

int fds[2];

void parentCode(){
    char buf1[20] = "aaaaaaaaaaaaaaaaaa";
    char buf2[20] = "bbbbbbbbbbbbbbbbbb";
    close(fds[0]);
    write(fds[1],buf1,20);
    write(fds[1],buf2,20);
    printf("end of parent\n");
}

void childCode(){
    char buf[100];
    int n,i;
    close(fds[1]);
    n=read(fds[0],buf,100);
    printf("no of chars read = %d\n",n);
    for(i=0;i<n;i++)
        printf("%c",buf[i]);
    printf("end of child\n");
}

int main(){
    int res ,i;
    pid_t p;
    res = pipe(fds);
    if(res == -1){
        perror("pipe");
        exit(0);
    }
    p=fork();
    if(p==0){
        childCode();

    }
    else{
        parentCode();
    }
    return 0;
}