#include <stdio.h>
#include <string.h>

int main(void)
{
    int len;
    char namn[6] = "Kalle";
    len = strcspn(namn, "e");
    printf("%d\n", len);
    return 0;
}
