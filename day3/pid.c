#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

int main(){
	
	printf("my process id:%d\n",getpid());
	printf("my parent pid=%d\n",getppid());
    while(1);
    return 0;
}
