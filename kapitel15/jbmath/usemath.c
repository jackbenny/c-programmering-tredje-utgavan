#include <stdio.h>
#include "jbmath.h"

int main(void)
{
    printf("En cirkel med diametern 5.5 har omkretsen %.3f\n",
           circumf(5.5));
    printf("En rektangel med sidorna 3 och 8.5 har arean %.3f\n",
           area(3, 8.5));
    printf("5 upphöjt till 6 är %ld\n", jbpow(5, 6));
    return 0;
}
