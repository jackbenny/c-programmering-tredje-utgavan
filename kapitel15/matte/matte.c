#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "minmattefunk.h"
#include "usage.h"

int main(int argc, char **argv)
{
    int opt;
    if (argc == 1)
    {
        printUsage(argv[0]);
        return 1;
    }
    
    while ((opt = getopt(argc, argv, "s:c:")) != -1)
    {
        switch (opt)
        {
        case 's':
            printf("%d squared is %d\n", atoi(optarg), 
                   kvadrat(atoi(optarg)));
            break;
        case 'c':
            printf("%d cubed is %d \n", atoi(optarg), 
                   kubik(atoi(optarg)));
            break;
        default:
            printUsage(argv[0]);
            return 1;
        }
    }
    return 0;
}
