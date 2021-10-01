#include <stdio.h>

void printUsage(char *arg)
{
    printf("Usage: %s (-s) | (-c) (integer)\n"
	   "-s = calculate the square of an integer\n"
	   "-c = calculate the cube of an integer\n", arg);
}
