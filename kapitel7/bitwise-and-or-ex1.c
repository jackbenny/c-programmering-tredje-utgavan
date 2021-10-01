#include <stdio.h>

int main(void)
{
    unsigned char a = 12; /* 0000 1100 */
    unsigned char b = 9;  /* 0000 1001 */
    unsigned char c, d;

    c = a & b;
    d = a | b;

    printf("OCH = %d\n", c);
    printf("ELLER = %d\n", d);

    return 0;
}
