#include <stdio.h>

int main(void)
{
    char namn[12];
    printf("Vad heter du? ");
    fgets(namn, sizeof(namn), stdin);
    printf("Hej %s, nu ska vi lära oss C!\n", namn);
    return 0;
}
