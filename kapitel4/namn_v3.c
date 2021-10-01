#include <stdio.h>
#include <string.h>

int main(void)
{
    char namn[12];
    printf("Vad heter du? ");
    fgets(namn, sizeof(namn), stdin);
    /* byt ut \n mot \0 på namn[index] */
    namn[strcspn(namn, "\n")] = '\0';
    printf("Hej %s, nu ska vi lära oss C!\n", namn);
    return 0;
}
