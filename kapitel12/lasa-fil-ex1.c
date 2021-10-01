#include <stdio.h>

int main(void)
{
    FILE *fp;
    signed char c;
    
    fp = fopen("test.txt", "r");
    while ((c = getc(fp)) != EOF)
        putchar(c);
    fclose(fp);

    return 0;
}
