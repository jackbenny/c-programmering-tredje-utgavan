#include <stdio.h>
#define SIZE 11

int main(void)
{
    int i;
    char namn[SIZE] = "Jack-Benny";
    printf("Adressen till 'namn': %p\n", (void*)&namn);

    for (i=0; i<SIZE; i++)
    {
        printf("Element %i -> %p\n", i, (void*)&namn[i]);
    }

    return 0;
}
