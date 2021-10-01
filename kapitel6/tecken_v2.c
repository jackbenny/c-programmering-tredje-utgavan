#include <stdio.h>

int main(void)
{
    char tecken;

    if ((tecken = getchar()) == 10)
        printf ("Inget tecken angavs\n");
    else
    {
        printf("Tecknet är: %c\n", tecken);
        if (tecken == 'A')
        {
            printf ("Du skrev ett versalt A\n");
        }
        else if (tecken == 'a')
        {
            printf("Du skrev ett gement a\n");
        }
        else
        {
            printf("Du skrev något tecken, förutom A eller a\n");
        }
    }
    return 0;
}
