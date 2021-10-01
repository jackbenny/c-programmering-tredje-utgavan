#include <stdio.h>
#include <string.h>

int main(void)
{
    union myUnion /* Samma syntax som för struct */
    {
        int x;
        float y;
        char z[20];
    } unionTest; /* Skapar en variabel unionTest ur myUnion */

    printf("Storleken är %lu bytes\n",
           (long unsigned int)sizeof(unionTest));

    /* Här arbetar vi med en medlem i taget, helt korrekt */
    unionTest.x = 500;
    printf("x = %d\n", unionTest.x);
    unionTest.y = 3.14;
    printf("y = %f\n", unionTest.y);
    strcpy(unionTest.z, "Hej hopp!");
    printf("z = %s\n", unionTest.z);
    
    return 0;
}
