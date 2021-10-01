#include <stdio.h>

int main(void)
{
    int langd, bredd, hojd;
    signed char ch;
    int i;
    FILE *fp;
    
    /* Kontrollera först om filen finns och om inte
    avsluta programmet och skriv ett felmeddelande */
    if ( (fp = fopen("konfigfil.txt", "r")) == 0)
    {
        printf("Filen finns inte!\n");
        return 1;
    }

    printf("Position innan läsning: %ld\n", ftell(fp));
    fscanf( fp, "längd: %d, bredd: %d, höjd: %d",
            &langd, &bredd, &hojd);

    printf("Lådan har en volym på %d cm3\n",
           (langd * bredd * hojd));
    printf("Position efter läsning: %ld\n\n", ftell(fp));

    printf("Läs tre byte från åttonde byten från starten:\n");
    fseek(fp, 8, SEEK_SET);
    for (i = 0; i<3; i++)
    {
        ch = fgetc(fp);
        putchar(ch);
    }
    printf("\nAktuell position: %ld\n\n", ftell(fp));

    printf("Flyttar markören 5 bytes framåt och läser resten:\n");
    fseek(fp, 5, SEEK_CUR);
    printf("Aktuell position: %ld\n", ftell(fp));
    while ((ch = fgetc(fp)) != EOF)
        putchar(ch);
    printf("\nAktuell position: %ld\n\n", ftell(fp));

    return 0;
}
