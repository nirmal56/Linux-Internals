#include<stdio.h>
#include<unistd.h>
#include<errno.h>

int main(){
    int ret , i ,cnt=0,cnt1=0,ret1;
    errno=0;
    ret = nice(1);
    ret1 = nice (5);

    if(ret==-1 && errno !=0)
        perror("nice");
    else    
        printf("nice value is now:%d",ret);
    while(1){
        printf("process with nice value %d count = %d\n",ret,cnt);
        for (int i=0; i<10000000; i++)
            cnt1++;
    }
      while(1){
        printf("process with nice value %d count = %d\n",ret1,cnt);
        for (int i=0; i<10000000; i++)
            cnt++;
    }
}