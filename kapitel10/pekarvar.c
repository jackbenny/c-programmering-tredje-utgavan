#include <stdio.h>
#define SIZE 11

int main(void)
{
    /* Skapa vanliga variabler & fält */
    float pi = 3.14159;
    char namn[SIZE] = "Jack-Benny";

    /* Deklarera pekarna */
    float *ppi;
    char *pnamn;

    /* Sätt pekarna till adressen av variablerna */
    ppi = &pi;
    pnamn = &namn[5];

    /* Skriv ut det som pekarna pekar på */
    printf("Pi = %.5f\n", *ppi);
    printf("Namn = %s\n", pnamn);

    return 0;
}
