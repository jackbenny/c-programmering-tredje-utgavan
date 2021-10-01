#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    struct stat fileinfo;
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s path/to/file\n", argv[0]);
        return 1;
    }

    stat(argv[1], &fileinfo);

    printf("Inode number: %lu\n", (unsigned long int)fileinfo.st_ino);
    printf("Size in bytes: %lu (%.2f kilobytes)\n",
           (unsigned long int)fileinfo.st_size,
           (float)fileinfo.st_size / 1024);
    printf("User-ID: %d\n", fileinfo.st_uid);
    printf("Group-ID: %d\n", fileinfo.st_gid);

    return 0;
}
