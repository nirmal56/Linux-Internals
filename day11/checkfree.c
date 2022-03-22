#include <stdio.h>
#include <stdlib.h>
void buggy()////////////////Lower boundary violation.
{
    int *intptr;
    int i;
    intptr = (int *)malloc(sizeof(int));
        *intptr = 100;
        printf("value at the ptr int ptr = %ld\n", (*intptr));
        free(intptr);
        *intptr=90;
}
int main()
{
    buggy();
    return 0;
}