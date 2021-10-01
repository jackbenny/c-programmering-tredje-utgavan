#include <stdio.h>

int main(void)
{
    float pi = 3.14159;
    printf("Adressen till 'pi' är: %p\n", (void*)&pi);

    return 0;
}
