#include <stdio.h>

int main(void)
{
    FILE *binfil;
    float x;
    if ( (binfil = fopen("flyttal.bin", "rb")) == 0 )
    {
        fprintf(stderr, "Kunde inte öppna filen\n");
        return 1;
    }
    fread(&x, sizeof(x), 1, binfil);
    printf("Flyttalet är: %f\n", x);
    fclose(binfil);
    return 0;
}
