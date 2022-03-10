#include<stdio.h>
int main(int argc, char *argv[]){
    int i;
    printf("\n filename:%s",argv[0]);
    printf("\n total args are: %d",argc);
    printf("\n args passsed:");

    for(int i=1;i<argc;i++){
        printf("%s",argv[i]);
    }
    printf("\n");
}