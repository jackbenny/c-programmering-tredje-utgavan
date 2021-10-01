#define _XOPEN_SOURCE 500
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>

void printUsage(char *arg);

int main(int argc, char* argv[])
{
    FILE *fp;
    int opt;
    pid_t process_id;
    char pidfile[] = "/tmp/daemon-sig-ex.pid";

    /* Kontrollera ifall PID-filen finns */
    if ( (fp = fopen(pidfile, "r")) == 0 )
    {
        fprintf(stderr, "Ingen PID-fil, körs verkligen demonen?\n");
        return 1;
    }
    /* Läs in PID till process_id variabeln */
    fscanf(fp, "%d", &process_id);

    /* Om inga argument angavs, skriv ut demonens PID */
    if (argc == 1)
        printf("Demonen körs med PID: %d\n", process_id);

    /* Behandla argument till programmet */
    while ((opt = getopt(argc, argv, "utqh")) != -1)
    {
        switch (opt)
        {
        case 'u':
            kill(process_id, SIGUSR1);
            break;
        case 't':
            kill(process_id, SIGTERM);
            break;
        case 'q':
            kill(process_id, SIGQUIT);
            break;
        case 'h':
            printUsage(argv[0]);
            return 0;
        default:
            printUsage(argv[0]);
            return 1;
        }
    }
    return 0;
}

void printUsage(char *arg)
{
    fprintf(stderr, "Usage: %s [-u] [-t] [-q] [-h]\n"
            "-u = send SIGUSR1 to daemon\n"
            "-t = send SIGTERM to daemon\n"
            "-q = send SIGQUIT to quit the daemon\n"
            "-h = display help\n", arg);
}
