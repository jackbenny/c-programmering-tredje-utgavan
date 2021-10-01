#include <stdio.h>

int main(void)
{
    char tecken;

    if ((tecken = getchar()) == 10)
        printf ("Inget tecken angavs\n");
    else
    {
        printf("Tecknet är: %c\n", tecken);
        if ((tecken >= 65) && (tecken <= 90))
            printf("Det är dessutom en versal bokstav\n");
        else if ((tecken >= 97) && (tecken <= 122))
            printf("Det är dessutom en gemen bokstav\n");
        else if ((tecken >= 48) && (tecken <= 57))
            printf("Det är en siffra\n");
        else
            printf("Tecknet är ingen bokstav och ingen siffra\n");
    }
    return 0;
}
