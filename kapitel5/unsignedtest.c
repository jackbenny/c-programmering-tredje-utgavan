#include <stdio.h>
#include <unistd.h>

int main(void)
{
    unsigned int i;
    for (i = 10; i >= 0; i--)
    {
        printf("%u\n", i);
        sleep(1);
    }
    return 0;
}
