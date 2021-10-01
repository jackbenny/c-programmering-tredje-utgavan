#include <stdio.h>

int main(void)
{
    unsigned char a = 140; /* 1000 1100 */
    unsigned char b;

    b = ~a;

    printf("b = %d\n", b); /* 0111 0011 */

    return 0;
}
