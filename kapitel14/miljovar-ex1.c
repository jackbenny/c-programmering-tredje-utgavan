#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    /* Spara ett värde för senare användning */
    const char* myhome = getenv("HOME");

    /* Skriv ut några miljövariabler */
    printf("Ditt UID är: %i\n", getuid());
    printf("Ditt GID är: %i\n", getgid());
    printf("Ditt användarnamn är: %s\n", getenv("USER"));
    printf("Det aktuella programmet heter: %s\n", getenv("_"));

    printf("Din hemkatalog är: %s\n", myhome);

    /* Testa om en variabel är satt eller inte */
    if (getenv("DISPLAY"))
    {
        printf("Du använder X-Window just nu\n");
    }
    else
    {
        printf("Du använder inte X-Window just nu\n");
    }
  
    return 0;
}
