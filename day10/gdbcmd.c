#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc,int *argv[]){
    int i;
    printf("file name:%s",argv[0]);
    printf("total args:%d",argc);
    printf("args passed:\n");
    for(int g=1;g<argc;g++){
        printf("%s\n",argv[g]);
    }

    return 0;
}