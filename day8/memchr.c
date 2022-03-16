#include<stdio.h>
#include<string.h>

int main(){
    const char str[]="linuxkernal#com";
    char * ret;
    const char ch ='#';
    printf("string before chr/scan is:%s\n",str);
    ret=memchr(str,ch,strlen(str));
    printf("string after **%c** is **%s**\n",ch,ret);
    // printf("%d",ret);
    return 0;
}