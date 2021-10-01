#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char* buffer;
    buffer = malloc(sizeof(char)*15);
    *buffer = '\0';
    strcpy(buffer, "Hejsan svejsan");
    printf("%s\n", buffer);
    free(buffer);
    return 0;
}
