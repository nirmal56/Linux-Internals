
#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

int main(){
	// fork();
	printf("stat1\n");
    fork();
	printf("stat2\n");
    // fork();
    return 0;
}
