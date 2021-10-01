#include <stdio.h>

int main(void)
{
    fprintf(stdout, "Text till stdout\n");
    fprintf(stderr, "Ett felmeddelande\n");
    return 0;
}
