#include <stdio.h>

int main(void)
{
    unsigned char a = 147;
    unsigned char b;

    b = a ^ 17;

    printf("b = %d\n", b);

    return 0;
}
