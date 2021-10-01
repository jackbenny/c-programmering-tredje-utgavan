#include <stdio.h>

void funk(void);

int main(void)
{
    funk();
    funk();
    funk();
    return 0;
}

void funk(void)
{
    static int j = 0;
    j++;
    printf("%d\n", j);
}
