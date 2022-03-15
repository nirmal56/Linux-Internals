/*
4.Write a program that implements all file operations(open/creat/write/read/lseek/close).
*/
#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

int main(){
	int fd1,fd2,fd3,len=60,rr;
	int x;
	char writebuf[60]="new linux file for all fille ops";
	char readbuf[60];
	
	fd1 = open ("a4w.txt",O_CREAT | O_RDWR,777);				//open
	write(fd1,writebuf,len);									//write

	fd1 = open ("sample.txt",O_RDONLY,777);						//open
	read(fd1,readbuf,len);										//read
	printf("read data is:%s\n",readbuf);
	
	fd2 = creat("a4w1.txt",777);								//creat
	close(fd2);
	close(fd1);													//close
	return 0;
}
