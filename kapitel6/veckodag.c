#include <stdio.h>

int main(void)
{
    int d;

    printf("Ange veckodag (1-7): ");
    scanf("%d", &d);

    /* Kontrollera först om veckodagen är giltig */
    if((d<0) || (d>7))
    {
        printf("Ogiltig veckodag, ange ett tal mellan 1-7\n");
        return 1;  /* Avsluta programmet med returkod 1
                      ifall veckodagen utanför 1-7 */
    }

    /* Nu använder vi switch för att behandla veckodagen */
    switch (d)
    {
    case(1):
        printf("Början på veckan\n");
        break;
    case(2):
        printf("Tisdag\n");
        break;
    case(5):
        printf("Fredag!\n");
        break;
    case(6):
        printf("Lördag, det är helg!!\n");
        break;
    case(7):
        printf("Söndag, det är fortfarande helg!!\n");
        break;
    default:
        printf("Mitten av veckan...\n");
        break;
    }
    return 0;
}
