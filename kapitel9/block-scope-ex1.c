#include <stdio.h>

void funk1(void);

int main(void)
{
    int i = 555;
    int x = 123;
    printf("i utanför for: %d\n", i);
    
    for (int i = 0; i <= 2; i++)
    {
        printf("i inuti for: %d\n", i);
        printf("x går att nå ifrån loopen och är: %d\n", x);
    }

    printf("i utanför och efter for: %d\n", i);
    funk1();
    printf("i i main är fortfarande: %d\n", i);
    return 0;
}
    
void funk1(void)
{
    int i = 999;
    printf("i inuti funk1: %d\n", i);
}
