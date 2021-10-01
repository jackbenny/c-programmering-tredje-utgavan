#include <stdio.h>
#include <string.h>

#define MAXLANGD 30
#define ANTAL 3

int main(void)
{
    FILE *fp;
    int i;
    struct minData
    {
        char fnamn[MAXLANGD];
        char enamn[MAXLANGD];
        int alder;
    };

    struct minData personer[ANTAL];

    if ( (fp= fopen("personer.bin", "rb")) == 0 )
    {
        fprintf(stderr, "Kan inte öppna filen\n");
        return 1;
    }

    /* Läs in strukturen från filen */
    fread(personer, sizeof(struct minData), ANTAL, fp);

    /* Loopa igenom alla personer i strukturen */
    for (i = 0; i<ANTAL; i++)
    {
        printf("Förnamn: %s\n", personer[i].fnamn);
        printf("Efternamn: %s\n", personer[i].enamn);
        printf("Ålder: %d\n\n", personer[i].alder);
    }

    return 0;
}
