#include<stdio.h>
#include<string.h>

int main(){
    const char buf1[10];
    const char buf2[10];
    int ret;
    memcpy(buf1,"madam",5);
    memcpy(buf2,"mad",5);
    ret = memcmp(buf1,buf2,5);
    if(ret>0){
        printf("buf1 greater than 2\n");
    }
    else if(ret<0){
        printf("buf2 greater than 1\n");
    }
    else{
        printf("same\n");
    }

    return 0;
}