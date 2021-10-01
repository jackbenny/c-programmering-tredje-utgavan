#include <stdio.h>

int main(void)
{
    for (int i=0; i<=10; i++)
        printf("i = %d\n", i);

    /* Nedanstående printf()-rad fungerar inte eftersom i är lokal
       för for-loopen ovan. Testa genom att av-kommentera raden */
    /* printf("Utanför loopen är i = %d\n", i); */
    
    int j;
    for (j=10; j>=0; j--)
        printf("j = %d\n", j);

    /* Detta kommer dock att fungera eftersom j deklarerades
       utanför for-loopen */
    printf("Utanför loopen är j = %d\n", j);
    return 0;
}
