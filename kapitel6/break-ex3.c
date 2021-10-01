#include <stdio.h>

int main(void)
{
    int i = 10;
    while (i>0)
    {
        printf ("i = %d\n", i);
        if (i == 6)
            break;
        i--;
    }
    return 0;
}
