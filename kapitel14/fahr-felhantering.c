#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Funktionsprototyp av isNumeric */
int isNumeric(const char *str);

int main(void)
{
    char c[10];
    float cels, f;
    while(fgets(c, sizeof(c), stdin) != NULL) 
    {
        if (isNumeric(c))
        {
            cels = atof(c);  /* char till float (stdlib.h) */
            f = cels*9/5+32;
            printf("%.1f\n", f);
        }
        else
        {
            fprintf(stderr, "Påträffade icke-numeriskt värde\n");
            return 1;
        }
    }
    return 0;
}

/* Funktionen för att kontrollera inmatade tecken */
int isNumeric(const char *str)
{
    if(strspn(str, "0123456789.-\n") == strlen(str)) /*string.h*/
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
