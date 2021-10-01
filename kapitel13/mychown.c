#define _XOPEN_SOURCE 500
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

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
        fprintf(stderr, "Could not change UID or GID\n");
        return 1;
    }

    return 0;
}
