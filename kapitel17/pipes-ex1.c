#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#define MAX 7

int main(void)
{
    int pipefd[2];
    pid_t pid;
    char line[MAX];

    pipe(pipefd);
    pid = fork();

    if (pid > 0)
    {
        close(pipefd[0]);
        write(pipefd[1], "Hejsan", MAX);
    }
    else
    {
        close(pipefd[1]);
        read(pipefd[0], line, MAX);
        printf("%s\n", line);
    }
    return 0;
}
