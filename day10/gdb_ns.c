#include<stdio.h>
#include<string.h>

void myprint(char *msg){
    if(msg!=NULL)
        printf("msg:=%s",msg);
}

int main(){
    char buff[]="linux";
    myprint(NULL);
    return 0;
}