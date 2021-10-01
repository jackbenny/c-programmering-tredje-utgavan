#include <stdio.h>

int main(void)
{
    unsigned char x = 211;  /* 1101 0011 */

    if (x & 64)
        printf("Den andra biten från vänster är satt\n");

    return 0;
}
