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
           (unsigned long int)sizeof(unionTest));

    /* Endast unionTest.z nedan kommer innehålla ett riktigt värde */
    unionTest.x = 500;
    unionTest.y = 3.14;
    strcpy(unionTest.z, "Hej hopp!");
    printf("x = %d\ny = %f\nz = %s\n", unionTest.x, unionTest.y, 
        unionTest.z);
    
    return 0;
}
