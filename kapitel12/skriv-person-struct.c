#include <stdio.h>
#include <string.h>

#define MAXLANGD 30
#define ANTAL 3

int main(void)
{
    FILE *fp;
    struct minData
    {
        char fnamn[MAXLANGD];
        char enamn[MAXLANGD];
        int alder;
    };

    struct minData personer[ANTAL];

    if ( (fp = fopen("personer.bin", "wb")) == 0 )
    {
        fprintf(stderr, "Kan inte öppna filen\n");
        return 1;
    }

    /* Skapa tre person i strukturen */
    strcpy(personer[0].fnamn, "Kalle");
    strcpy(personer[0].enamn, "Anka");
    personer[0].alder = 31;

    strcpy(personer[1].fnamn, "Lisa");
    strcpy(personer[1].enamn, "Anka");
    personer[1].alder = 28;

    strcpy(personer[2].fnamn, "Fnatte");
    strcpy(personer[2].enamn, "Anka");
    personer[2].alder = 8;

    /* Skriv ut strukturen till en fil */
    fwrite(personer, sizeof(struct minData), ANTAL, fp);

    return 0;
}
