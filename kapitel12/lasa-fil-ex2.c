#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp;
    int strSize, readSize;
    char *buffer;
    fp = fopen("test.txt", "r");

    /* Ta reda på storleken och återgå sen till start */
    fseek(fp, 0, SEEK_END);
    strSize = ftell(fp);
    rewind(fp);

    /* Skapa dynamiskt minne för filens innehåll */
    buffer = calloc(sizeof(char), strSize+1);

    /* Läs in filens innehåll och spara antalet inlästa
       tecken i 'readSize' */
    readSize = fread(buffer, sizeof(char), strSize, fp);

    fclose(fp); /* Vi är klara med fp så stäng den */

    printf("%s\n\n", buffer);
    printf("Storleken är %d tecken och vi läste in %d tecken\n", 
           strSize, readSize);

    free(buffer); /* Frigör det dynamiska minnet */

    return 0;
}
