#include<stdio.h>

int main(){
    // //referencing
    // int val=5;
    // int *ref;
    // ref=&val;
    // //derefrencing
    // int deref;
    // deref=*ref;
    int *i;
    float *f;
    char *c;

    printf("value of i=%d",*i);
    printf("value of f=%f",*f);
    printf("value of c=%c",*c);
    
    i=NULL;
    f=NULL;
    c=NULL;

    printf("value of i=%d",*i);
    printf("value of f=%f",*f);
    printf("value of c=%c",*c);

    // prcntf("%d\t%d\t") 
}