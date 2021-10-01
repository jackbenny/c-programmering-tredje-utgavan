#include <stdio.h>
#include <math.h>

int main(void)
{
    float taljare = 19.5;
    float namnare = 4.3;
    printf("fmod(%0.1f, %0.1f) = %0.1f\n", taljare, namnare,
           fmod(taljare,namnare));
    return 0;
}
