#include <stdio.h>

int main(void)
{
    int x = 5;

    do
    {
        x++;
        printf("X är nu: %d\n", x);
    } while (x < 5);

    return 0;
}
