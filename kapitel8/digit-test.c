#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char chr1 = '9';
    char chr2 = 'a';
    printf("chr1: %d\n", isdigit(chr1));
    printf("chr2: %d\n", isdigit(chr2));
    return 0;
}
