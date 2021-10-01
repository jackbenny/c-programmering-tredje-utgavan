#define _XOPEN_SOURCE 500
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    pid_t pid;
    pid = fork();
    if (pid == 0)
    { 
        printf("Jag är barnprocessen\n");
        sleep(30);
    }
    else if (pid > 0)
    {
        printf("Jag är förälderprocessen\n");
        sleep(30);
    }
    else
    {
        fprintf(stderr, "Något gick fel med fork()\n");
        return 1;
    }
    return 0;
}
