#include <stdio.h>

int main(void)
{
    char c = 'A';
    float x = 3.14;
    float y = 3.999;
    int z = 45;
    long int lx = 922337203685477580;
    long int ly = 345;
    int ii = 429496729;
    
    printf("Casta float %f till int: %d\n", x, (int)x);
    printf("Casta float %f till int: %d\n", y, (int)y);
    printf("Casta int %d till float: %f\n", z, (float)z);
    printf("Casta char %c till int: %d\n", c, (int)c);
    printf("Casta long int %li till int: %d\n", lx, (int)lx);
    printf("Casta long int %li till int: %d\n", ly, (int)ly);
    printf("Casta int %d till short int: %d\n", ii, (short int)ii);
    
    return 0;
}
