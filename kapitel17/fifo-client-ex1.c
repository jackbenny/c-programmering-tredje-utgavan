#include <stdio.h>
#include <unistd.h>

#define FIFONAM "/tmp/testfifo"

int main(void)
{
    FILE *fp;
    signed char c;
    if ( access(FIFONAM, R_OK) != 0 )
    {
        fprintf(stderr, "Problem att öppna %s\n", FIFONAM);
        return 1;
    }
    fp = fopen(FIFONAM, "r");
    while ((c = getc(fp)) != EOF)
        putchar(c);
    fclose(fp);
    return 0;
}
