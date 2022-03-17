#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void my_memcpy(char *src, char *dest, size_t nbyte){
    for(int i=0;i<nbyte;i++){
        *dest=*src;
        dest++;
        src++;
    }
}

int main(){

    char str1[20]="abcd";
    char str2[20];

    my_memcpy(str1,str2,20);
    printf("%s\n%s\n",str1,str2);

}
