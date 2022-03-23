#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>
int main(){
    char buff_com[5];
    strcpy(buff_com,"ls -l");
    printf("system() library uses fork() to create a child process\n");
    printf("child process executes execl() which loads and run new program provided by sysytem() segment\n");
    int x = system(buff_com);
    // int x = system(NULL);//return 0 when shel not available ,1 when shell available.
    printf("%d\n",x);
    return 0;
}