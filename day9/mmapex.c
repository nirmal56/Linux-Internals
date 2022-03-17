#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/mman.h>
#include<string.h>
int main(){
    int fd;
    char *c;
    struct stat fileinfo;

    fd=open("kernal.txt",O_CREAT|O_RDWR,0777);
    write(fd,"linux kernal technology\n",25);
    fstat(fd,&fileinfo);
    printf("file size is %d\n",fileinfo.st_size);

    c = mmap(0,fileinfo.st_size, PROT_READ | PROT_WRITE, MAP_PRIVATE,fd,0);
    perror("mmap");

    // strcpy(c,"linux kernal");
    printf("%s\n",c);
    munmap(c,fileinfo.st_size);
    return 0;
}