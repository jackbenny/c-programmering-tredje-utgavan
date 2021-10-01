#include <stdio.h>
#define LANGD 5

int main(void)
{
    int i;
    int x[LANGD] = {0, 1, 2, 3, 4};
    int *px;

    px = x;

    for (i = 0; i<LANGD; i++)
    {
        printf("%d: %p\n", *px, (void*)px);
        px = px + 1;
    }
    return 0;
}
