#include<stdio.h>
#include<string.h>

int main(){
    const char dest[10]="stringnew";
    const char src[10]="stringold";
    
    printf("before memmove dest = %s ,src = %s\n",dest,src);

    memmove(dest , src, 3);

    printf("after memmove dest = %s ,src = %s\n",dest,src);
    return 0;
}