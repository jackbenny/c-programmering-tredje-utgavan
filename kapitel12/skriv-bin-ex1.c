#include <stdio.h>

int main(void)
{
    FILE *binfil;
    float x;
    /* Kontrollera om fopen lyckades öppna filen
       i skrivläge */
    if ( (binfil = fopen("flyttal.bin", "wb")) == 0 )
    {
        /* Skriv felmeddelande till stderr */
        fprintf(stderr, "Kan inte skriva till fil\n");
        return 1;
    }
    printf("Skriv ett flyttal: ");
    scanf("%f", &x);
    fwrite(&x, sizeof(x), 1, binfil);
    fclose(binfil);
    return 0;
}
