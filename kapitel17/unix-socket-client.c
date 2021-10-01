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
#define MAXLEN 32

int main(void)
{
    const char sockname[] = "/tmp/tidssocket";
    int fd;
    struct sockaddr_un addr;
    char recvbuffer[MAXLEN];

    /* skapa en socket fildeskriptor */
    fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if ( fd == -1 )
    {
        perror("Create socket failed");
        return 1;
    }
    /* sätt adressfamiljen och socket-filen */
    addr.sun_family = AF_UNIX;
    strcpy(addr.sun_path, sockname);

    /* anslut till servern */
    if ( (connect(fd, (const struct sockaddr*) &addr, 
        sizeof(struct sockaddr_un))) == -1 )
    {
        perror("Can't connect");
        fprintf(stderr, "The server is down?\n");
        return 1;
    }
    /* läs tiden från servern */
    if ( (read(fd, recvbuffer, MAXLEN)) == -1 )
    {
        perror("Can't read");
        return 1;
    }
    printf("Server time is: %s", recvbuffer);
    write(fd, "Thank you for the time", 23);
    return 0;
}
