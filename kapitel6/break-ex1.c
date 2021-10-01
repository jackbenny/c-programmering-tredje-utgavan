#include <stdio.h>

int main(void)
{
    int i;
    
    for(i=10; i>0; i--)
    {
        printf("i = %d\n", i);
        if (i==4)
            break;
    }
    
    return 0;
}
