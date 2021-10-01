#define _XOPEN_SOURCE 500
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <signal.h>
#include <syslog.h>
#include <fcntl.h>

char pidfile[] = "/tmp/daemon-sig-ex.pid";

void sigHandler(int sig);
void shutDown(int sig);

int main(void)
{
    pid_t process_id = 0;
    pid_t sid = 0;
    FILE *fp;
    /* Skapa barn/child process */
    process_id = fork();
 
    /* Hantera eventuellt fel vid fork() */
    if (process_id < 0)
    {
        fprintf(stderr, "fork misslyckades!\n");
        exit(1);
    }
    /* Avsluta förälderprocessen */
    else if (process_id > 0)
    {
        exit(1);
    }
 
    /*  Starta en ny session */
    sid = setsid(); 
  
    if(sid < 0)
    {
        /* Avsluta ifall det inte gick att skapa en ny
           session */
        fprintf(stderr, "Misslyckades att skapa en ny session\n");
        exit(1);
    }
    /* Gör en ny fork för att förhindra att demonen kan bli en
       sessionsledare */
    process_id = fork();
  
    /* Hantera eventuellt fel vid fork() */
    if (process_id < 0)
    {
        fprintf(stderr, "fork misslyckades!\n");
        exit(1);
    }
    /* Avsluta föräldern den eftersom allt arbete kommer att
       utföras av demonen. Skriv också demonens PID-fil */
    else if (process_id > 0)
    {
        printf("Demonens PID: %d \n", process_id);
        fp = fopen(pidfile, "w");
        fprintf(fp, "%d", process_id);
        fclose(fp);
        exit(0);
    }
   
    /* Sätt umask till 022 (rw-r--r-- / rwx-r-xr-x) */
    umask(022);
   
    /* Ändra aktuell katalog till / */
    chdir("/");
   
    /* Stäng stdin, stdout och stderr. Dessa behövs inte
       i en demonprocess */
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
    open("/dev/null", O_RDONLY); /* 0 = stdin */
    open("/dev/null", O_WRONLY); /* 1 = stdout */
    open("/dev/null", O_RDWR); /* 2 = stderr */
   
    /* Registrera signalhanterarna, en för varje signal
       som vi vill fånga upp */
    signal(SIGUSR1, sigHandler);
    signal(SIGTERM, sigHandler);
    signal(SIGABRT, shutDown);
    signal(SIGQUIT, shutDown);
    signal(SIGINT, shutDown);
    
    /* Demonens arbete... */
    for(;;)
    {
        sleep(5);
    }
    return 0;
}

void sigHandler(int sig)
{
    if (sig == SIGUSR1)
    {
        /* Skriv till syslog-demonen */
        syslog(LOG_DAEMON, "Tog emot SIGUSR1");
    }
    else if (sig == SIGTERM)
    {
        /* Samma som ovan */
        syslog(LOG_DAEMON, "Tog emot SIGTERM");
    }
    else
    {
        syslog(LOG_DAEMON, "Någonting hände med demonen...");
    }
    /* Signalhanteraren återställs efter första signalen,
       vi måste därför sätta den igen */
    signal(sig, sigHandler);
}

void shutDown(int sig)
{
    syslog(LOG_DAEMON, "Demonen avslutas");
    /* Ta bort PID-filen */
    if ( unlink(pidfile) == -1 )
        syslog(LOG_DAEMON, "Kunde inte ta bort PID-filen");
    exit(0);
}
