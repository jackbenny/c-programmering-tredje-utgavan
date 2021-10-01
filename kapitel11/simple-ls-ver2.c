#define _XOPEN_SOURCE 500
#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>

void printUsage(char *arg);

int main(int argc, char **argv)
{
    int opt;
    unsigned int typ = 0;
    char *path = ".";
    
    /* Skapa pekare och struct */
    DIR           *d;
    struct dirent *dir;
    struct stat s;
    
    /* Behandla argument med getopt */
    while ((opt = getopt(argc, argv, "hafdp:")) != -1)
    {
        switch (opt)
        {
        case 'a':
            typ = -1;
            break;
        case 'f':
            typ = S_IFREG;
            break;
        case 'd':
            typ = S_IFDIR;
            break;
        case 'p':
            path = optarg;
            break;
        case 'h':
            printUsage(argv[0]);
            return 0;
        default:
            printUsage(argv[0]);
            return 1;
        }
    }

    /* Byt katalog med chdir() för att stat() ska
       se filerna i rätt katalog */
    chdir(path);

    d = opendir(path);
    while ((dir = readdir(d)) != NULL)
    {
        if ( typ == 0 )
        {
            printf("%s\n", dir->d_name);
        }
        else
        {
            stat(dir->d_name, &s);
            /* Se kapitlet om 'Bitvisa operationer' */
            if ((s.st_mode & S_IFMT) == typ)
                printf("%s\n", dir->d_name);
        }
    }
        return 0;
}

void printUsage(char *arg)
{
    printf("Usage: %s [-a] [-f] [-d] [-p path]\n"
           "    -a to list all types (default)\n"
           "    -f to list only files\n"
           "    -d to list only directories\n"
           "    -p to specify a directory\n", arg);
}
