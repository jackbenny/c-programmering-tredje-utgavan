#include <stdio.h>

int arsiffra(char); /* Funktionsprototyp */

int main(void)
{
    char chr1 = '9';
    char chr2 = 'a';
    printf("chr1: %d\n", arsiffra(chr1));
    printf("chr2: %d\n", arsiffra(chr2));
    return 0;
}

/* Här följer funktionskroppen för
   funktionen arsiffra() */
int arsiffra(char c)
{
    if ((c >= '0') && (c <= '9'))
        return 1;
    else
        return 0;
}
