#include <stdio.h>
#include <string.h>

int main(void)
{
    struct artikel
    {
		char namn[50];
		int antal;
		float pris;
    };

    struct artikel lager;

    strcpy(lager.namn, "Skruv");
    lager.antal = 12;
    lager.pris = 1.5;

    printf("Följande artiklar finns i lager\n\n");
    printf("Namn: %s\tAntal på lager: %d\tPris: %.2f\n",
	   lager.namn, lager.antal, lager.pris);
    
    return 0;
}
