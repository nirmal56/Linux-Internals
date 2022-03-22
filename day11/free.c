#include <stdio.h>
#include <stdlib.h>
void buggy(int *p)////////////////Lower boundary violation.
{
    p[0]=10;
        free(p);
}
int main()
{
    int *ptr;
    buggy(ptr);
    free(ptr);
    return 0;
}