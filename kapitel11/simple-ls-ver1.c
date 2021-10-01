#define _XOPEN_SOURCE 500
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

void printUsage(char *arg);

int main(int argc, char **argv)
{
    unsigned int typ;
    char opt[4] = { 0 };
    
    /* Skapa pekare och struct */
    DIR           *d;
    struct dirent *dir;
    struct stat s;

    /* Läs in aktuell katalog */
    d = opendir(".");
    /* Om 'd' INTE är sant (! = inte sant) */
    if (!d)
    {
        printf("Kan inte läsa aktuell katalog\n");
        return 1;
    }
    
    /* Behandla arugment */
    if (argc == 1)
    {
        strncpy(opt, "-a", 3);
    }
    else if (argc == 2)
    {
        strncpy(opt, argv[1], 3);
    
        /* Hjälptext */
        if ( strcmp(opt, "-h") == 0 )
            printUsage(argv[0]);

        /* Visa endast filer */
        else if ( strcmp(opt, "-f") == 0 )
        {
            typ = S_IFREG;
        }

        /* Visa endast kataloger */
        else if ( strcmp(opt, "-d") == 0 )
        {
            typ = S_IFDIR;
        }

        /* Visa alla filer */
        else if ( strcmp(opt, "-a") == 0 )
        {
            ;
        }

        /* Om vi angav ett felaktigt argument */
        else
        {
            printUsage(argv[0]);
            return 1;
        }
    }
    /* Om vi angav fel antal argument */
    else
    {
        printUsage(argv[0]);
        return 1;
    }

    /* Skriv ut innehållet i katalogen */
    while ((dir = readdir(d)) != NULL)
    {
        if ( strcmp(opt, "-a") == 0 )
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
        
    /* Stäng "d" och returnera noll */
    closedir(d);
    return 0;
}

void printUsage(char *arg)
{
    printf("Usage: %s [-a] [-f] [-d]\n"
       "    -a to list all types (default)\n"
       "    -f to list only files\n"
       "    -d to list only directories\n", arg);
}
