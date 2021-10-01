#include <stdio.h>

int main(void)
{
    /* Ger sant om antingen 4 > 5, eller om 5 < 10,
       eller om både 4 > 5 och 5 < 10. Minst ett utav
       villkoren måste således vara uppfyllda. */
    if (4 > 5 || 5 < 10)
        printf("4 > 5 eller 5 < 10\n");

    /* Ger sant om både 4 > 5 och 5 < 10, annars inte.
       Båda villkoren måste således vara uppfyllda. */
    if (4 > 5 && 5 < 10)
        printf("4 > 5 och 5 < 10\n");

    return 0;
}
