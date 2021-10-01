#include <stdio.h>

int main(void)
{
    int i;
    char fnamn[] = "Jack-Benny";
    char *enamn = "Persson";

    printf("Förnamn: %s\n", fnamn);
    printf("Efternamn: %s\n\n", enamn);

    printf("Förnamn: %p %p\n", (void*)&fnamn, (void*)fnamn);
    printf("Efternamn: %p %p\n", (void*)&enamn, (void*)enamn);

    /* Skriv ut ett tecken i taget med mellanslag mellan varje
       tecken. Detta görs genom att addera 1 till pekarvariabeln
       för varje iteration */
    for (i=0; i<=7; i++)
    {
        printf("%c ", *enamn);
        enamn = enamn + 1;
    }
    printf("\n");
    return 0;
}
