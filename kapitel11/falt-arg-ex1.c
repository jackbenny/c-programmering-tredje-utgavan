#include <stdio.h>

void say(char *namn);

int main(void)
{
    char namn01[] = "Kalle";
    char *namn02 = "Lisa";

    say(namn01);
    say(namn02);
    say("Jack-Benny");
	return 0;
}

void say(char *namn)
{
    printf("Hej %s, hur är läget?\n", namn);
}
