#include<stdio.h>
#include<signal.h>

int main(){
    pid_t pid;
    int sig_no;
    printf("enter pid which ypou wanna end\n");
    scanf("%d",&pid);
    printf("enter signal code: \n");
    scanf("%d",&sig_no);/////enter signal code as 2
    
    kill(pid,sig_no);
    // return 0;
}