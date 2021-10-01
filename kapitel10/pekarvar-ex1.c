#include <stdio.h>

int main(void)
{
    /* Skapa vanliga variabler & fält */
    float pi = 3.14159;

    /* Deklarera pekarna */
    float *ppi;
    
    /* Sätt pekaren till adressen av variabeln */
    ppi = &pi;

    /* Skriv ut det som pekaren pekar på och dess innehåll */
    printf("Adressen till 'pi': %p\n", (void*)&pi);
    printf("'pi' innehåller: %.5f\n\n", pi);
    printf("Adressen till 'ppi': %p\n", (void*)&ppi);
    printf("'ppi' pekar på värdet: %.5f\n", *ppi);
    printf("'ppi' innehåller: %p\n", (void*)ppi);
    
    return 0;
}
