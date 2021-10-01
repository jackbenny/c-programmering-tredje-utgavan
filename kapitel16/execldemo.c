#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main(void)
{
    sleep(15);
    execl("/usr/bin/man", "man", "ls", (char *)NULL);
    perror("execl");

    return 0;
}
