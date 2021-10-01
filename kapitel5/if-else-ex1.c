#include <stdio.h>

int main(void)
{
    int a = 5;
    int b = 10;

    if (a < b)
    {
        printf ("%d är mindre än %d\n", a, b);
        printf ("Uttrycket (%d < %d) ger talet: %d\n", a, b, (a<b));
    }
    else  /* Körs om (a < b) INTE är sant */
    {
        printf ("%d är större än %d\n", a, b);
    }

    /* Fristående if-satser */
    if (22)
        printf("22 är 'sant'\n");
    if (0)
        printf("0 är däremot 'inte sant', och denna rad "
            "körs aldrig\n");
    if (-2)
        printf("Även negativa tal är 'sanna'\n");
    return 0;
}
