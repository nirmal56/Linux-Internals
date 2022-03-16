#include<stdio.h>
#include<unistd.h>

int main(int argc, int argv[]){
    long int page_size = sysconf(_SC_PAGESIZE);
    printf("page size:%ld\n",page_size);
    void * c1 =sbrk(0);
    printf("program break address:%p\n",c1);
    printf("size of char:%lu\n",sizeof(char));

    c1 = (void*)((char*)c1+9);
    printf("c1:%p\n",c1);
    brk(c1);
    void *c2 =sbrk(0);
    printf("prog break address:%p\n",c2);
}