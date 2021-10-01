#include <stdio.h>

int main(int argc, char **argv)
{
    int i;
    printf("Du har angett %d st argument\n", argc);
    for (i = 0; i<argc; i++)
    {
        printf("Argument %d är: %s\n", i, argv[i]);
    }
    return 0;
}
