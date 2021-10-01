#include <stdio.h>

int main(void)
{
    unsigned char a = 128;
    unsigned char b;

    b = a | 1;

    printf("b = %d\n", b);

    return 0;
}
