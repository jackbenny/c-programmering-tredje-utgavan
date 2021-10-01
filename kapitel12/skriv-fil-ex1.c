#include <stdio.h>

int main(void)
{
    FILE *fp;
    char namn1[] = "Knatte";
    char namn2[] = "Fnatte";

    fp = fopen("test.txt", "w");

    fprintf(fp, "%s, %s och Tjatte\n"
             "bor alla i Ankeborg.\n\n", namn1, namn2);
    fputs("Kalle och Lisa bor också i Ankeborg.\n", fp);
    
    fclose(fp);

    return 0;
}
