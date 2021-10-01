#include <stdio.h>
#include <stdlib.h>

float circum(float d);

int main(int argc, char *argv[])
{
    float di;
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s diamater\n", argv[0]);
        return 1;
    }

    di = atof(argv[1]);
    printf ("Circumference of a circle with a diamater %.2f is"
            " %.2f\n", di, circum(di));
    return 0;
}

float circum(float d)
{
    float pi = 3.14159265;
    return (pi*d);
}
