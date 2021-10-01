#include <stdio.h>

int main(void)
{
    printf("En char: %lu byte\n",
           (unsigned long int)sizeof(char));
    printf("En vanlig int: %lu byte\n",
           (unsigned long int)sizeof(int));
    printf("En long int: %lu byte\n",
           (unsigned long int)sizeof(long int));
    printf("En short int: %lu byte\n",
           (unsigned long int)sizeof(short int));
    return 0;
}
