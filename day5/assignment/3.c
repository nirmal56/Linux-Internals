/*
3. A program that replaces old program with new program data and is expected to display the currently running processes in a 
hierarchical tree format.
*/
#include<stdio.h>
#include<unistd.h>



int main(){
printf("I'm going to open a info1.txt from vim\n");
// int ret = execl("/usr/bin/vim", "vim","info1.txt", 0);
int ret = execl("/usr/bin/pstree", "pstree", 0, 0);
if(ret == -1){
printf("execl returned error %d\n", ret);
}
return 0;
}