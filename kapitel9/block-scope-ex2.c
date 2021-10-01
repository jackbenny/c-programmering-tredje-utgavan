#include <stdio.h>

int main(void)
{
    int i = 10;
    
    for (int i = 0; i <= 3; i++)
    {
        printf("i inuti första for: %d\n", i);
    }
    
    printf("i utanför for: %d\n", i);

    for ( ; i<= 13; i++)
    {
        printf("i inuti andra for: %d\n", i);
    }
    
    return 0;
}
