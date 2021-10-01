#define _XOPEN_SOURCE 600
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <inttypes.h>

int main(void)
{
    FILE *fp;
    off_t filesize;
    int fd, readSize;
    struct stat fileinfo;
    char* buffer;
    fp = fopen("test.txt", "r");
    
    fd = fileno(fp);  /* Hämta fildeskriptorn och spara i fd */
    fstat(fd, &fileinfo);  /* Hämta all information till 'fileinfo' */
    filesize = fileinfo.st_size; /* Spara filens storlek i filesize */
                                 /* från 'fileinfo.st_size' */

    buffer = calloc(sizeof(char), filesize+1);
    readSize = fread(buffer, sizeof(char), filesize, fp);
    buffer[filesize] = '\0';

    printf("%s\n\n", buffer);
    printf("Fildeskriptor: %d\n", fd);
    printf("Filens storlek är %jd byte och vi har läst in %d byte\n",
           (intmax_t)filesize, readSize);

    return 0;
}
