#include <stdio.h>
#include <unistd.h>

int main(void)
{
    write(1, "Hejsan\n", 7);
    return 0;
}
