#include <stdio.h>
#include <string.h>

int main(void)
{
    char a[] = "Kalle";
    char b[] = "Lisa";
    
    /* Skriver ut adressen till "Hej" */
    printf("%lu\n", (long unsigned int)"Hej");

    /* Jämför strängar */
    if(strcmp(a, b) == 0)
        printf("%s och %s är detsamma\n", a, b);
    else if(strcmp(a, "Kalle") == 0)
        printf("%s = Kalle\n", a);
    else
        printf("Ingen match\n");
    
    return 0;
}
