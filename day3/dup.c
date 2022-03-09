#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

int main(){
	int fd1,fd2,fd3,fd4;
	
	fd1 = open ("l1.txt",O_CREAT | O_RDWR | O_TRUNC,777);				//open
	
	fd2 = open ("l2.txt",O_CREAT | O_RDWR | O_TRUNC,777);				//open
	
	printf("fd1=%d\n",fd1);
	printf("fd2=%d\n",fd2);
	fd3=dup(fd1);
	fd4=dup2(fd2,10);
	printf("fd3 of fd1=%d\n",fd3);
	printf("fd4 of fd2=%d\n",fd4);
	close(fd4);
	close(fd3);
	close(fd2);
	close(fd1);								//close
	return 0;
}
