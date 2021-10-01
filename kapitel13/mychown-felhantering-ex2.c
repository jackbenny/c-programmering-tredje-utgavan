#define _XOPEN_SOURCE 500
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    uid_t uid;
    gid_t gid;

    if (argc != 4)
    {
        fprintf(stderr, "Usage: %s <file> <uid> <gid>\n", argv[0]);
        return 1;
    }

    uid = (uid_t)atoi(argv[2]);
    gid = (gid_t)atoi(argv[3]);
    
    if (chown(argv[1], uid, gid) == -1)
    {
        printf("%i\n", errno); /* Visar vad errno innehåller */
        printf("%s\n", strerror(errno)); /* Meddelandet i klartext */
        return 1;
    }

    return 0;
}
