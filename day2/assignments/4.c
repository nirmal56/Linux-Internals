/*
4.Write a program that implements all file operations(open/creat/write/read/lseek/close).
*/
#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

int main(){
	int fd1,fd2,len,rr;
	int x;
	char writebuf[60]="new linux file for all fille ops";
	char readbuf[60];
	
	fd1 = open ("a4w.txt",O_CREAT | O_RDWR,777);				//open
	fd2 = creat("a4w1.txt",777);						//creat
	
	write(fd1,writebuf,60);							//write
	read(fd1,readbuf,60);							//read
	printf("read data is:%s\n",readbuf);
	
	//for(int i; i<30;i++){printf("%c",readbuf[i]);}
	//while((rr= read(fd1,readbuf,1))>0){printf("%c",rr);}
	
	write(fd2,writebuf,60);							//write
	read(fd2,readbuf,60);							//read
	printf("read data is:%s\n",readbuf);
	
	close(fd2);
	close(fd1);								//close
	return 0;
}
