#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int fd4;

    fd4 = open("sample.txt", O_RDWR, 777); //to read the file(in readonly mode)

    if (fd4>0) { //checking file exist
        printf("file exist\n");
        char to_write[] = "this lines will be added to file. this one is also be added";
        int leng = strlen(to_write);

        char to_read[leng];
        if(write(fd4, to_write, leng)<0){ // writing permision in file
            printf("failed to write\n");
            
        } else if(read(fd4, to_read, leng)<0){ //reading permision in file
            printf("unable to read the file\n");
        }
    } else{
        printf("not exists\n");
    }
    
    int close(int fd4);

    return 0;
}