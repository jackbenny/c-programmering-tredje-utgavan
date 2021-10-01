    #include <stdio.h>
    
    int kvadrat(int x);
    
    int main(void)
    {
        int z = 5;
        printf("z = %d\n", z);
        printf("Kvadraten på z = %d\n", kvadrat(z));
        printf("z = %d\n", z);
        return 0;
    }
    
    int kvadrat(int x)
    {
        x = x * x;
        return x;
    }
