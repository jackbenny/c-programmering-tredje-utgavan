#include <stdio.h>

int main(void)
{
    printf("En char: %zu byte\n", sizeof(char));
    printf("En vanlig int: %zu byte\n", sizeof(int));
    printf("En long int: %zu byte\n", sizeof(long int));
    printf("En short int: %zu byte\n", sizeof(short int));
    return 0;
}
