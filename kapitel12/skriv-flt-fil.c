#include <stdio.h>

int main(void)
{
    float y[3] = {3.14, 5.55, 9.56};
    FILE *fp;
    if ( (fp = fopen("test.bin", "wb")) == 0 )
    {
        fprintf(stderr, "Kan inte öppna filen\n");
        return 1;
    }
    fwrite(&y, sizeof(y), 1, fp);
	fclose(fp);
    return 0;
}
