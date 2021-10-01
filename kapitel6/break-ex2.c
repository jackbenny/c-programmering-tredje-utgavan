#include <stdio.h>

int main(void)
{
    int i;
    int j;
    
    for(i=10; i>0; i--)
    {
        printf("i = %d\n", i);
        for (j=30; j<=40; j++)
        {
            printf("j = %d\n", j);
            if (j==33)
            {
                break;
            }
        }
    }
    return 0;
}
