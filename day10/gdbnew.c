#include<stdio.h>
#include<string.h>

int main(){
    char *src;
    src = malloc(1<<8);
    fgets(src,500,stdin);
    printf("%s\n",src);
    return 1;
}