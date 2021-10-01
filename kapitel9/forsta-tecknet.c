#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 20

int main(void)
{
    char *a;
    int i;
    a = calloc(SIZE, sizeof(char));
    strcpy(a, "Hej alla glada");

    printf("Strängen: %s\n", a);

    *a = '\0'; /* "Initialisera" igen */
    printf("Strängen efter ny initialisering: %s\n", a);

    printf("\nTecken för tecken efter ny initialisering:\n");
    for (i=0; i<SIZE;  i++)
    {
        if (*a == '\0')
            printf("tecken: NULL\n");
        else
            printf("tecken: %c\n", *a);
        a++;
    }
    /* Vi måste flytta tillbaks pekaren innan vi frigör */
    free(a-SIZE);
    return 0;
}
