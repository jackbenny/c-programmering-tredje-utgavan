#include <stdio.h>

extern int x;
extern int y;

int main(void)
{
    /* Kommer inte att fungera eftersom
       y är static i filen 
       fungerande-scope-fil2.c
    */
    printf("x = %d\n", x);
    printf("y = %d\n", y);
    return 0;
}
