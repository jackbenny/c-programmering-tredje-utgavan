#include <stdio.h>

int main(void)
{
    float y[3];
    int i;
    FILE *fp;
    if ( (fp = fopen("test.bin", "rb")) == 0 )
    {
        fprintf(stderr, "Kan inte öppna filen\n");
        return 1;
    }
    fread(&y, sizeof(y), 1, fp);
    for (i = 0; i<3; i++)
		printf("%f\n", y[i]);
	fclose(fp);
    return 0;
}
