#include <stdio.h>

float omkrets(float diameter);

int main(void)
{
    float d = 15;
    float o = omkrets(d);
    printf("Omkretsen för en cirkel med diametern "
       "%.3f är %.3f\n", d, o);
    return 0;
}

float omkrets(float diameter)
{
    float pi = 3.14159265;
    return (pi * diameter);
}
