#include<fcntl.h>
#include<stdio.h>
int main(){
	int fd1,fd2,fd3;
	fd1=open("linux111.txt",O_CREAT,0777);
	fd2=open("linux112.txt",O_WRONLY | O_CREAT,0777);
	printf("fd returned is 1 :%d\n",fd1);
	printf("fd returned is 2 :%d\n",fd2);
	return 0;
}
