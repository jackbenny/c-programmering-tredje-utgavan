#include <stdio.h>
#include <string.h>

char *say(char namn[]);

int main(void)
{
    printf("%s\n", say("Jack-Benny"));
    return 0;
}

char *say(char namn[])
{
    char str[50] = { 0 };
    strncat(str, "Hej ", 4);
    strncat(str, namn, 45);
    return str;
}
