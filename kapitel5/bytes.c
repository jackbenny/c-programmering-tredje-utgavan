#include <stdio.h>

int main(void)
{
    printf("En char: %lu byte\n", sizeof(char));
    printf("En vanlig int: %lu byte\n", sizeof(int));
    printf("En long int: %lu byte\n", sizeof(long int));
    printf("En short int: %lu byte\n", sizeof(short int));
    return 0;
}
