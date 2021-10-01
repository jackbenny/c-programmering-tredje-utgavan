#include <stdio.h>

void skrivprimtal(int min, int max);

int main(void)
{
    int a = 2;
    int b = 30;
    printf("Alla primtal mellan %d och %d\n", a, b);
    skrivprimtal(a, b);
    return 0;
}


void skrivprimtal(int min, int max)
{
    int i, j, primtal;
    for (i=min; i<=max; i++)
    {
        primtal = 1;
        for(j=2; j<i; j++)
        {
            if(i%j == 0)
            {
                primtal = 0;
                break;
            }
        }
        if(primtal == 1)
        {
            printf("%d är ett primtal\n", i);
        }
    }
}
