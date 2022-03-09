#include<stdio.h>
#include<unistd.h>

int main(){
    printf("going to execut 'ls' prigram\n");

    execl("/bin/ls","ls","-lh",0);

    printf("i executed this program");
    printf("i executed this program");
    printf("i executed this program");
    
    return 0;
}