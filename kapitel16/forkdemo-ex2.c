#define _XOPEN_SOURCE 500
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    pid_t pid;
    int status;
    pid = fork();
    if (pid == 0)
    { 
        execl("/usr/bin/man", "man", "ls", (char *)NULL);
        perror("execl");
    }
    else if (pid > 0)
    {
        waitpid(pid, &status, 0);
        printf("Barnet är klart, återgår till förälderprocessen\n");
        printf("Barnet returnerade %i\n", status);
    }
    else
    {
        fprintf(stderr, "Något gick fel med fork()\n");
        return 1;
    }
    
    return 0;
}
