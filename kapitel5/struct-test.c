#include <stdio.h>

int main(void)
{
    struct test1
    {
        short int a;  /* 2 bytes                     */
                      /* 2 bytes utfyllnad (2+2=4)   */
        int b;        /* 4 bytes           (4)       */
        char c;       /* 1 byte                      */
        char d;       /* 1 byte                      */
                      /* 2 bytes utfyllnad (1+1+2=4) */
    };

    struct test2
    {
        int b;        /* 4 bytes           (4)       */
        char c;       /* 1 bytes                     */
        char d;       /* 1 bytes                     */
        short int a;  /* 2 bytes           (1+1+2=4) */
    };

    printf("Storleken av test1: %lu bytes\n",
           (long unsigned int)sizeof(struct test1));
    printf("Storleken av test2: %lu bytes\n",
           (long unsigned int)sizeof(struct test2));
    return 0;
}
