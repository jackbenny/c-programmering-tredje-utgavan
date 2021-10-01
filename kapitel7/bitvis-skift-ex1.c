#include <stdio.h>

int main(void)
{
    unsigned char a = 16; /* 00010000 */

    printf("%d\n", (a = a >> 1)); /* 8 = 00001000 */
    printf("%d\n", (a = a >> 1)); /* 4 = 00000100 */
    printf("%d\n", (a = a >> 2)); /* 1 = 00000001 */

    printf("%d\n", (a = a << 1)); /* 2   = 00000010 */
    printf("%d\n", (a = a << 4)); /* 32  = 00100000 */
    printf("%d\n", (a = a << 1)); /* 64  = 01000000 */
    printf("%d\n", (a = a << 1)); /* 128 = 10000000 */
    
    return 0;
}
