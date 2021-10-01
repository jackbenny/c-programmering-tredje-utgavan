#include <stdio.h>

int main(void)
{
    int langd, bredd, hojd;
    FILE *fp;

    /* Kontrollera först om filen finns och om inte
       avsluta programmet och skriv ett felmeddelande */
    if ( (fp = fopen("konfigfil.txt", "r")) == 0)
    {
        printf("Filen finns inte!\n");
        return 1;
    }

    /* Läs in de olika "fälten" från filen till rätt
       variabel */
    fscanf( fp, "längd: %d, bredd: %d, höjd: %d",
        &langd, &bredd, &hojd);

    /* Skriv ut volymen */
    printf("Lådan har en volym på %d cm3\n",
       (langd * bredd * hojd));

    return 0;

}
