#include <stdio.h>
#include <unistd.h>

int main(void)
{
    write(STDOUT_FILENO, "Hejsan\n", 7);
    return 0;
}
