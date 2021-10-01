#include <stdio.h>

void inc(int *tal);

int main(void)
{
    int x = 5;
    printf("x är nu: %d\n", x);
    inc(&x);
    printf("x är nu: %d\n", x);
    return 0;
}

void inc(int *tal)
{
    *tal = *tal + 3;
}
