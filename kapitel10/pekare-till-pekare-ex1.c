#include <stdio.h>

int main(void)
{
    int x = 5;
    int *px;
    int **ppx;

    px = &x;
    ppx = &px;

    printf("%d\n", **ppx);

    return 0;
}
