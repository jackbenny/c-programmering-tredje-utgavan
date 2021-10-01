#include <stdio.h>

int main(void)
{
    unsigned char a = 12; /* 0000 1100 */
    unsigned char b = 9;  /* 0000 1001 */

    if((a & b) == 8)
        printf("Korrekt, talet blir åtta\n");
    if((a | b) == 13)
        printf("Korrekt, talet blir tretton\n");

    return 0;
}
