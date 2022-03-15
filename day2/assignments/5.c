/*
5.Write a program that creates a file with a 4K bytes free space. (Such files are called files with holes.)
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
char buf1[]="LAB ";
char buf2[]="OS Linux";

int main(){    
	int fd;
	if ((fd=creat("file.txt", 0666)) < 0) {
		printf("Creation error");
		exit(1);
	}
	if (write(fd, buf1, sizeof(buf1)) < 0){
	    printf("Writing error");
	    exit(2);
	}
	if (lseek(fd, 4096, SEEK_SET) < 0){
	    printf("Positioning error");
	    exit(3);
	}
	if (write(fd, buf2, sizeof(buf2)) < 0){
	    printf("Writing error");
	    exit(2);
	}
}
/*
Trace the execution of the program with the help of the following commands:

ls -l

stat file.txt

od -c file.txt    

 */
