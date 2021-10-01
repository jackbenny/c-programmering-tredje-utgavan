#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *say(char namn[]);

int main(void)
{
    char *mening = say("Jack-Benny");
    printf("%s\n", mening);
    free(mening);
    printf("Lisa hojtar: %s\n", mening);
    return 0;
}

char *say(char namn[])
{
    char *str;
    str = calloc(50, sizeof(char));
    strncat(str, "Hej ", 4);
    strncat(str, namn, 45);
    return str;
}
