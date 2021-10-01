#include <stdio.h>

int main(void)
{
    int i = 6;
    i = i * 2;

    for ( ; i>0; i--)
    {
        printf("i = %d\n", i);
    }
    return 0;
}
