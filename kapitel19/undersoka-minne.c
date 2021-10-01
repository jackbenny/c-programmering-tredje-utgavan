#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *a;
    a = malloc(10*sizeof(char));
    *a = '\0';
    strcpy(a, "Hej hej");
    printf("Strängen %s\n", a);
    *a = '\0';
    printf("Strängen %s\n", a);

    free(a);
    return 0;
}
