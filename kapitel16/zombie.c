#define _XOPEN_SOURCE 500
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    pid_t pid;
    pid = fork();
    if (pid == 0)
    { 
        printf("Jag är barnprocessen och kommer bli en zombie\n");
        exit(0);
    }
    else if (pid > 0)
    {
        printf("Jag är föräldern och kommer att köras i "
               "100 sekunder\n");
        sleep(100);
    }
    else
    {
        fprintf(stderr, "Något gick fel med fork()\n");
        return 1;
    }
    
    return 0;
}
