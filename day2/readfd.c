#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

int main(){
	int fd;
	char buf[300];
	int res=300;
	fd=open("writefd.c",O_CREAT|O_RDWR,777);
	printf("%d",fd);
	if(fd<0){
		printf("not opened\n");
	}
	read(fd,buf,res);
	printf("%s\n",buf);
	close(fd);
}
