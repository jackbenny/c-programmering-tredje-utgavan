#include <stdio.h>

int main(void)
{
    int a = 5;
    int b = 10;
    int c = 15;

    if (a > b)
        printf("%d är större än %d\n", a, b);
    else if (a > c)
        printf("%d är större än %d\n", a, c);
    else if (a == b)
        printf("%d är lika stor som %d\n", a, b);
    else
        printf("Inget av de ovanstående villkoren var sanna\n");

    printf("Här fortsätter koden som vanligt\n");
    
    return 0;
}
