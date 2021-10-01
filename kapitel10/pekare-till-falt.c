#include <stdio.h>
#define SIZE 11

int main(void)
{
    char namn[SIZE] = "Jack-Benny";
    printf("Adressen till 'namn': %p\n", (void*)&namn);

    return 0;
}
