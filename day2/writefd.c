#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int  main(){
	int fd,len;
	int x;
	char writebuf[60]="new linux file pro gto write in file.";
	
	fd = open ("linuxabc.txt",O_CREAT | O_RDWR,0777);
	
	write(fd,writebuf,60);//buf is there in file 
	close(fd);
return 0;
}
