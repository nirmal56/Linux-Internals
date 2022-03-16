#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char *str1="linux",*str2="kernal";
    char *name =(char *)alloca (strlen (str1) + 1);
    strcat(strcpy(name,str1),str2);
    stpcpy(stpcpy(name,str1),str2);
    printf("copied data is %s\n",name);
}