#include <stdio.h>
#include <string.h>
#define ARTIKLAR 3

int main(void)
{
    typedef struct artikel
    {
        char namn[50];
        int antal;
        float pris;
    }ART;

    ART lager[ARTIKLAR];
    int i;

    strcpy(lager[0].namn, "Skruv");
    lager[0].antal = 12;
    lager[0].pris = 1.5;

    strcpy(lager[1].namn, "Hammare");
    lager[1].antal = 2;
    lager[1].pris = 159;

    strcpy(lager[2].namn, "Skruvmejsel");
    lager[2].antal = 5;
    lager[2].pris = 79.90;

    printf("Följande artiklar finns i lager\n");
    printf("-------------------------------\n\n");
    for (i = 0; i<ARTIKLAR; i++)
    {
        printf("Namn: %-10s\tAntal på lager: %d\tPris: %.2f\n",
           lager[i].namn, lager[i].antal, lager[i].pris);
    }
    
    return 0;
}
