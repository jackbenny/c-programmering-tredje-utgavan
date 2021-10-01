#include <stdio.h>
#include "skrivprm.h"

int main(void)
{
    int min;
    int max;
    
    printf("Ange minsta talet: ");
    if(!scanf("%d", &min))
    {
        printf("Ange endast heltal\n");
        return 1;
    }
    
    printf("Ange största talet: ");
    if(!scanf("%d", &max))
    {
        printf("Ange endast heltal\n");
        return 1;
    }
    
    skrivprimtal(min, max);
    
    return 0;
}
