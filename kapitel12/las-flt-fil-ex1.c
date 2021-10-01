#include <stdio.h>

int main(void)
{
    float y[10];
    int bytes, antal, i;
    FILE *fp;
    if ( (fp = fopen("test.bin", "rb")) == 0)
    {
        fprintf(stderr, "Kan inte öppna filen\n");
        return 1;
    }
    fseek(fp, 0, SEEK_END); /* Flytt till slutet av filen*/
    bytes = ftell(fp); /* Totala antalet bytes */
    rewind(fp); /* Flytta markören till början av filen */
    printf("Antal bytes i filen: %d\n", bytes);
    antal = bytes / sizeof(float); /* Hur många element */
    printf("Antal element: %d\n", antal);
    fread(&y, sizeof(float), antal, fp);
    /* Skriv ut alla flyttalen från filen */
    for (i = 0; i<antal; i++)
        printf("%f\n", y[i]);
    fclose(fp);
    return 0;
}
