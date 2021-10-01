#include <stdio.h>

int main(void)
{
    int i;
    char a[5] = "B";
    char b[5] = { 0 };

    printf("char a:\n");
    for (i = 0; i<5; i++)
    {
        if (a[i] == '\0')
            printf("tecken: NULL\n");
        else
            printf("tecken: %c\n", a[i]);
    }

    printf("\nchar b:\n");
    for (i = 0; i<5; i++)
    {
        if (b[i] == '\0')
            printf("tecken: NULL\n");
        else
            printf("tecken: %c\n", b[i]);
    }
    
    return 0;
}
