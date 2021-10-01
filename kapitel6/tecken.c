#include <stdio.h>

int main(void)
{
    char tecken;

    if ((tecken = getchar()) == 10)
        printf ("Inget tecken angavs\n");
    else
        printf("Tecknet är: %c\n", tecken);
    return 0;
}
