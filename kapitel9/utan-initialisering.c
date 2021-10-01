#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *a, *b;
    a = malloc(300);
    
    strcat(a, "hej hej");
    printf("%s\n", a);
    free(a);

    b = malloc(30);
    strcat(b, "hej igen");
    printf("%s\n", b);
    free(b);
    
    return 0;
}
