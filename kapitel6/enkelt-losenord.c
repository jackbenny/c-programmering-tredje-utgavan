#include <stdio.h>
#include <string.h>

int main(void)
{
    char guess[10];
    char pass[] = "kalle";
    while (strcmp(guess, pass))
    {
        printf("Skriv in lösenordet: ");
        fgets(guess, sizeof(guess), stdin);
        guess[strcspn(guess, "\n")] = '\0';
    }
    printf("Du lyckades!\n");
    return 0;
}
