#include<stdio.h>
#include<string.h>

struct A{
    int roll;
    char name[40],gender __attribute__((aligned(2)));
    float height;
}__attribute__((packed));

int main(){
    struct A first;
    printf("\n size of roll A %3d\n",sizeof(first.roll));
    printf("\n size of name A %3d\n",sizeof(first.name));
    printf("\n size of gender A %3d\n",sizeof(first.gender));
    printf("\n size of height A %3d\n",sizeof(first.height));
    printf("\n size of struct A %3d\n",sizeof(first));
}
