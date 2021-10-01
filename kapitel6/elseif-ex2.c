#include <stdio.h>

int main(void)
{
    int a = 10;
    int b = 15;

    if (a < 20)
        printf("Detta är den enda raden som kommer skrivas ut\n");
    else if (b < 20)
        printf("Jag är också sann, men kommer inte skrivas ut\n");
    else
        printf("Jag kommer inte heller skrivas ut...\n");
    return 0;
}
