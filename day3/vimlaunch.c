#include<stdio.h>
#include<unistd.h>

int main(){
   int ret;
   ret=execl("/user/bin/vim","vim","info1.txt",0);
   if(ret==0)
    printf("kal ana abhi nahi khulega\n");
    return 0;
}