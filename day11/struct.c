#include<stdio.h>
#include<string.h>
struct student{
    int roll;
    char name[40],gender;
    float height;
}first;

int main(){
    struct student second;
    struct student third={103,"hari prasad",'m',5.11};
    printf("\nrollno.\t\t\t\t\tname\t\tgender\t height");
    first.roll=10;
    strcpy(first.name,"babulal aapte");
    first.gender='m';
    first.height=5.6;
    printf("\n %3d\t%40s\t%c\t%1.2f",first.roll,first.name,first.gender,first.height);
    printf("\n %3d\t%40s\t%c\t%1.2f\n",third.roll,third.name,third.gender,third.height);
    
}