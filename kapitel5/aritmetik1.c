#include <stdio.h>

int main(void)
{
    int a = 5;
    float b = 7.5;
    int c;

    printf("Heltalet: %d\n", a);
    printf("Flyttalet: %f\n", b);

    /* Aritmetik med heltal och flyttal */
    printf("%d + %f = %f\n", a, b, (a+b));

    /* Se upp, här skalas decimaltecknet bort! */
    c = (a+b);
    printf("%d + %f = %d\n", a, b, c);

    return 0;
}
