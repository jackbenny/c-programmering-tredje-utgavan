#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char c[10];
    float cels, f;
    while(fgets(c, sizeof(c), stdin) != NULL) 
    {
        cels = atof(c);  /* gör om char till float (stdlib.h) */
        f = cels*9/5+32;
        printf("%.1f\n", f);
    }
    return 0;
}
