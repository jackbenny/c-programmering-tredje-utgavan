#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *meningen;

    /* Allokera minnet */
    meningen = malloc(sizeof(char)*24);
    *meningen = '\0'; /* Initialisera strängen ("noll-terminera") */
    strcpy(meningen, "meningen med livet är");
    printf("%s\n", meningen);
    
    /* Utöka minnet till 'meningen' */
    meningen = realloc(meningen, sizeof(char)*40);
    strcat(meningen, " att programmera");
    printf("%s\n", meningen);

    /* Frigör minnet */
    free(meningen);

    return 0;
}
