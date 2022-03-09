#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

int main(){
	int fd1,fd2,fd3,fd4;
	
	fd1 = open ("l3.txt",O_CREAT | O_RDWR | O_TRUNC,777);				//open
	
	fd3= fcntl(fd1,F_DUPFD);
	
	printf("fd1=%d\n",fd1);
	printf("fd3 of fd1=%d\n",fd3);
	close(fd3);
	close(fd1);														//close
	return 0;
}
