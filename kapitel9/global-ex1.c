#include <stdio.h>

void funk(void);

int x = 5;

int main(void)
{
    printf("x = %d\n", x);
    printf("++x = %d\n", ++x);
    funk();
    printf("++x = %d\n", ++x);
    return 0;
}

void funk(void)
{
    printf("++x = %d\n", ++x);
}
