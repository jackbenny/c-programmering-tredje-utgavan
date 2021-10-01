#include <stdio.h>
int main(void)
{
    int a = 140; /* 0 1000 1100 */
    int b;
    b = ~a;
    printf("b = %d\n", b); /* 1 0111 0011 */
    return 0;
}
