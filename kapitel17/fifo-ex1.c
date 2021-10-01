#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <stdlib.h>

#define FIFONAM "/tmp/testfifo"
  
/* Skapa fifofd i det globala scopet så att
   vi kan stänga den ifrån signalhanteraren. */
int fifofd;

void cleanUp(int signum);

int main(void)
{
    char msg[] = "Ett meddelande till klienterna\n";

    /* Registrera signalhanterare för vanliga "avsluts-signaler" */
    signal(SIGINT, cleanUp);
    signal(SIGQUIT, cleanUp);
    signal(SIGABRT, cleanUp);
    signal(SIGTERM, cleanUp);
    /* Ignorera SIGPIPE, annars avslutas programmet när 
       mottagaren stängs */
    signal(SIGPIPE, SIG_IGN);

    /* Skapa FIFOn. S_IWUSR och S_IRUSR är detsamma som för
       open() och creat() */
    if ( mkfifo(FIFONAM, S_IWUSR | S_IRUSR) != 0)
    {
        if (errno == EEXIST)
        {
            fprintf(stderr, "FIFOn finns redan, använder den\n");
        }
        else
        {
            perror("mkfifo");
            return 1;
        }
    }

    /* Öppna FIFOn */
    fifofd = open(FIFONAM, O_WRONLY);
    if (fifofd < 0)
    {
        perror("open");
        return 1;
    }

    /* Skriv meddelanden i en oändlig loop */
    while(1)
    {
        write(fifofd, msg, sizeof(msg));
        sleep(1); /* Vänta en sekund mellan varje körning */
    }
    /* Hit bör vi aldrig komma, men fall i fall så städar vi upp */
    unlink(FIFONAM);
    close(fifofd);
    return 0;
}

void cleanUp(int signum)
{
    /* Stäng fildeskriptorn */
    if ( close(fifofd) == -1 )
        perror("cleanUp - close");

    /* Radera FIFO-filen från systemet & avsluta programmet */
    if ( unlink(FIFONAM) == -1 )
    {
        perror("cleanUp - unlink");
        exit(1);
    }
    exit(0);
}
