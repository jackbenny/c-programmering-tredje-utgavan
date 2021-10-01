#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *a;
    a = malloc(30*sizeof(char));
    memset(a, '\0', 29);
    strcat(a, "Hej svejs!");
    printf("%s\n", a);
    memset(a, 'A', 15);
    printf("%s\n", a);
    return 0;
}
