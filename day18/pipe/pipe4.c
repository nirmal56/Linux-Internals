#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main(){
    int p[2];
    pipe(p);
    printf("read the end of pipe = %d \t write end of file = %d \n",p[0],p[1]);
    if(fork()){
        char s[20];
        printf("in parent Enter data.. \n");
        scanf("%s",s);
        write(p[1], s, strlen(s)+1);
    }
    else{           //child
        char buf[20];
        printf("in child..\n");
        read(p[0],buf,sizeof(buf));
        printf("child process printing data of the parent process %s\n",buf);
    }
    return 0;
}