#include <stdio.h>
#define LANGD 3
    
int main(void)
{
    int i;
    char *ord[LANGD];
    char *pc;
    char **ppc;

    ord[0] = "hund";
    ord[1] = "katt";
    ord[2] = "kanin";

    /* Skriv ut de tre strängarna */
    for (i = 0; i < LANGD; i++)
    {
        printf("%s\n", ord[i]);
    }
    printf("\n");

    /* Skriv ut tecken för tecken */
    for (i = 0; i < LANGD; i++)
    {
        ppc = ord + i;
        pc = *ppc;
        while (*pc != '\0')
        {
            printf("%c ", *pc);
            pc = pc + 1;
        }
        printf("\n");
    }
    
    return 0;
}
