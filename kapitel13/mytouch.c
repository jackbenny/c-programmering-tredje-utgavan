#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }
    /* Rättigheterna nedan blir 644, Read/Write user, 
       Read group, Read others */
    creat(argv[1], S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (errno != 0)
    {
        perror("creat");
        return 1;
    }
    return 0;
}
