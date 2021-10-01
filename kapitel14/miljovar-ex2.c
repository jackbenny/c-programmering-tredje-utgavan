#define _XOPEN_SOURCE 600
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    setenv("MINVAR", "J-B", 0); /* sätt variabeln (0 = skriv ej 
                                   över ev. befintlig variabel) */
    printf("%s\n", getenv("MINVAR")); /* testa om det fungerade */
    return 0;
}
