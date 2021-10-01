#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    if (system("man ls") == -1)
        fprintf(stderr, "Could not create child process\n");
    return 0;
}
