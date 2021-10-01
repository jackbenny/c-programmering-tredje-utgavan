#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *a, *b;
    a = calloc(30, sizeof(char));
    
    strcat(a, "hej hej");
    printf("%s\n", a);
    free(a);

    b = calloc(30, sizeof(char));
    strcat(b, "hej igen");
    printf("%s\n", b);
    free(b);
    
    return 0;
}
