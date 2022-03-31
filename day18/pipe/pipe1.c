#include<stdio.h>
#include<unistd.h>

int main(){
    int fds[2];
    int res,i;
    char  buf1[20]="abcdefghijk";
    char  buf2[20]="lmnopqrstu  xyz";
    char buf3[40];

    res = pipe(fds);
    if(res == -1){
        perror("\npipe\n");
        exit(1);
    }
    write(fds[1],buf1,20);
    // read(fds[0],buf3,40);
    write(fds[1],buf2,20);
    read(fds[0],buf3,40);
    for(i=0;i<40;i++){
        printf("%c",buf3[i]);
    }
    printf("\n");
}