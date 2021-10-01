#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#define MAXLEN 32

void cleanUp(int signum);
const char sockname[] = "/tmp/tidssocket";
int connfd;
int datafd;

int main(void)
{
    struct sockaddr_un addr;
    char buffer[MAXLEN];
    char recvbuffer[MAXLEN];
    time_t current_time;
    struct tm *local_time;

    /* registrera signalhanterarna */
    signal(SIGTERM, cleanUp);
    signal(SIGABRT, cleanUp);
    signal(SIGQUIT, cleanUp);
    signal(SIGINT, cleanUp);

    /* skapa en socket fildeskriptor */
    connfd = socket(AF_UNIX, SOCK_STREAM, 0);
    if ( connfd == -1 )
    {
        perror("Create socket failed");
        return 1;
    }
    /* sätt adressfamiljen till UNIX-socket */
    addr.sun_family = AF_UNIX;
    strcpy(addr.sun_path, sockname);
    /* knyt ihop namnet och adressen och casta 
       sockaddr_un till sockaddr) */
    if ( (bind(connfd, (const struct sockaddr*)&addr, 
        sizeof(struct sockaddr_un))) == -1 )
    {
        perror("Binding socket failed");
        return 1;
    }
    /* lyssna efter anslutningar */
    if ( (listen(connfd, 20)) == -1 )
    {
        perror("Listen error");
        return 1;
    }

    /* acceptera anslutningen, skapa en ny data-fildeskriptor,
       och skicka tiden till klienten */
    while(1)
    {
        datafd = accept(connfd, NULL, NULL);
        if (datafd == -1 )
        {
            perror("Accept error");
            return 1;
        }
        printf("Client connected, sending time\n");
        current_time = time(NULL);
        local_time = localtime(&current_time);
        strcpy(buffer, asctime(local_time));
        write(datafd, buffer, MAXLEN);
        read(datafd, recvbuffer, MAXLEN);
        printf("Client respons: %s\n", recvbuffer);
        close(datafd); /* stäng datafd efter varje anrop */
    }
    return 0; /* fall i fall */
}

void cleanUp(int signum)
{
   printf("Quitting and cleaning up\n");
   close(datafd);
   close(connfd);
   unlink(sockname);
   exit(0);
}
