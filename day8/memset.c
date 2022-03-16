#include<stdio.h>
#include<string.h>

int main(){
    const char str[]="linuxkernal.com";
    const char ch ='#';
    printf("string before initialization is:%s\n",str);
    memset(str,ch,strlen(str)+5);
    printf("string after set is:%s\n",str);
    return 0;
}