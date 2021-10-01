#include <stdio.h>

int main(void)
{
    char fnamn[] = "Jack-Benny";
    char *enamn = "Persson";

    printf("Förnamn: %s\n", fnamn);
    printf("Efternamn: %s\n\n", enamn);

    printf("Förnamn: %p %p\n", (void*)&fnamn, (void*)fnamn);
    printf("Efternamn: %p %p\n", (void*)&enamn, (void*)enamn);

    return 0;
}
