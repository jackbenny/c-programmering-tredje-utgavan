#include <stdio.h>

int main(void)
{
    int idag;
    enum veckodag { mandag = 1, tisdag, onsdag,
            torsdag, fredag, lordag, sondag };
    idag = onsdag;

    if ( idag == lordag || idag == sondag )
    {
        printf("Idag är det helg\n");
    }
    else
    {
        printf("Idag är det vardag\n");
    }

    return 0;
}
