#define _XOPEN_SOURCE 500
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(void)
{
    pid_t process_id = 0;
    pid_t sid = 0;
    /* Skapa barn/child process */
    process_id = fork();
    /* Hantera eventuellt fel vid fork() */
    if (process_id < 0)
    {
        fprintf(stderr, "fork failed!\n");
        exit(1);
    }
    /* Förälderprocessen/parent process. Avsluta den */
    else if (process_id > 0)
    {
        exit(0);
    }
    /*  Starta en ny session */
    sid = setsid(); 
    if(sid < 0)
    {
        /* Avsluta ifall det inte gick att skapa en ny
           session */
        fprintf(stderr, "Failure to set new session\n");
        exit(1);
    }
    /* Gör en ny fork (dubbel-fork). Detta blir demonen */
    process_id = fork();
    /* Hantera eventuellt fel vid fork() */
    if (process_id < 0)
    {
        fprintf(stderr, "fork failed!\n");
        exit(1);
    }
    /* Förälderprocessen/parent process.
       Avsluta den eftersom allt arbete kommer att
       utföras av demonen. Skriv också ut demonens PID */
    else if (process_id > 0)
    {
        printf("Daemon process: %d \n", process_id);
        exit(0);
    }
    /* Sätt umask till 022 (rw-r--r-- / rwx-r-xr-x) */
    umask(022);
    /* Ändra aktuell katalog till / */
    chdir("/");
    /* Stäng stdin, stdout och stderr och återöppna dem till
       /dev/null. Dessa behövs inte i en demonprocess */
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
    open("/dev/null", O_RDONLY); /* 0 = stdin */
    open("/dev/null", O_WRONLY); /* 1 = stdout */
    open("/dev/null", O_RDWR); /* 2 = stderr */
    /* Här börjar demonens arbete... */
    for(;;)
    {
        sleep(5);
    }
}
