#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
int main(){
	int fd,len;
	char writebuf[300]="holla, all file descriptors are here";
	char readbuf[300];
	fd=open("linuxkernal.txt",O_CREAT|O_RDWR,777);
	len = write(fd,writebuf,300);
	printf("return value of write oprion:%d\n",len);
	
	lseek(fd,4,SEEK_SET);
	read(fd,readbuf,len);
	printf("data from buffer: %s\n",readbuf);
	close(fd);
	return 0;		
}
