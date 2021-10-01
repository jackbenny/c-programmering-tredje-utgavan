#include <stdio.h>

float medel(int tal[], int antal);

int main(void)
{
    int x[] = {40, 42, 39, 37, 28};
    printf("Medelvärdet är: %.1f\n", medel(x, 5));
    return 0;
}

float medel(int tal[], int antal)
{
    int i;
    int sum = 0;
    for (i = 0; i<antal; i++)
        sum = sum + tal[i];

    return ((float)sum / antal);
}
