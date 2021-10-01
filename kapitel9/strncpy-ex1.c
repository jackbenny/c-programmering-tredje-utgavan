#include <stdio.h>
#include <string.h>

int main(void)
{
    char stor[20] = "Hej Kalle & Lisa!";
    char liten[10] = "XXXXXXXXX";

    strncpy(liten, stor, sizeof(liten)-1);

    printf("stor = %s\n", stor);
    printf("liten = %s\n", liten);

    return 0;
}
