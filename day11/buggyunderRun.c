#include <stdio.h>
#include <stdlib.h>
extern int EF_PROTECT_BELOW;
void buggy()////////////////Lower boundary violation.
{
    int *intptr;
    int i;
    intptr = (int *)malloc(sizeof(int) * 5);
    printf("malloc checking addr=%08x and size = %d\n", intptr, sizeof(int) * 5);
    for (int i = 0; i < 3; i++)
    {
        *intptr = 100;
        printf("value at the ptr int ptr = %ld\n", (*intptr));
        intptr--;
    }
}
int main()
{
    buggy();
    return 0;
}