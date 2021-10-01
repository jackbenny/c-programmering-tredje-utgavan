#include <stdio.h>

int main(void)
{
    /* Korrekt storlek från början på x & y */
    float y[3];
    int x[3];    
    int i;
    FILE *fp;
    if ( (fp = fopen("test.bin", "rb")) == 0 )
    {
        fprintf(stderr, "Kan inte öppna filen\n");
        return 1;
    }
    fread(&y, sizeof(y), 1, fp); /* Först flyttalen */
    fread(&x, sizeof(x), 1, fp); /* Sen heltalen... */
    for (i = 0; i<3; i++)
        printf("%f\n", y[i]);

    for (i = 0; i<3; i++)
        printf("%d\n", x[i]);
    return 0;
}
