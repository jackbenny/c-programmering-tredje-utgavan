#include <stdio.h>
#include <string.h>

int main(void)
{
    typedef char text[50];   /* Nytt alias 'text' för char[50] */
    typedef char tiny;       /* Nytt alias 'tiny' för char */

    text namn;
    text adress;
    text ort = "Ankeborg";
    tiny knattarna = 3;

    printf("Vad heter du? ");
    fgets(namn, sizeof(text), stdin);
    printf("Vilken gatuadress bor du på? ");
    fgets(adress, sizeof(text), stdin);
    namn[strcspn(namn, "\n")] = '\0';
    adress[strcspn(adress, "\n")] = '\0';
    
    printf("En 'text' är %lu tecken stor.\n",
           (unsigned long int)sizeof(text));
    printf("Hej %s, från %s %s.\n", namn, adress, ort);
    printf("Knattarna är %d st.\n", knattarna);

    return 0;
}
