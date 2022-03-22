#include<stdio.h>
#include<string.h>

struct A{
    int roll;
    char name[40],gender;
    float height;
};

int main(){
    struct A first;
    printf("\n size of struct A %3d\n",sizeof(first.roll));
    printf("\n size of struct A %3d\n",sizeof(first.name));
    printf("\n size of struct A %3d\n",sizeof(first.gender));
    printf("\n size of struct A %3d\n",sizeof(first.height));
    printf("\n size of struct A %3d\n",sizeof(first));
}