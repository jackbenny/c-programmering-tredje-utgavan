#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#if __STDC_VERSION__ >= 199901L
#define C99
#include <inttypes.h>
#endif

int main(int argc, char *argv[])
{
    struct stat fileinfo;
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s path/to/file\n", argv[0]);
        return 1;
    }

    stat(argv[1], &fileinfo);

    #ifdef C99
    printf("C99 (or newer)\n");
    printf("Inode number: %ju\n",
           (uintmax_t)fileinfo.st_ino);
    printf("Size in bytes: %jd (%.2f kilobytes)\n",
           (intmax_t)fileinfo.st_size,
           (double)fileinfo.st_size / 1024);
    #else
    printf("C89\n");
    printf("Inode number: %lu\n", (unsigned long int)fileinfo.st_ino);
    printf("Size in bytes: %lu (%.2f kilobytes)\n",
           (unsigned long int)fileinfo.st_size,
           (float)fileinfo.st_size / 1024);
    #endif
    printf("User-ID: %d\n", fileinfo.st_uid);
    printf("Group-ID: %d\n", fileinfo.st_gid);

    return 0;
}
