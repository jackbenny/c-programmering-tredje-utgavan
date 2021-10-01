#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(void)
{
    int fd;
    int readstat;
    off_t filesize;
    struct stat fileinfo;
    char wbuf[] = "Hejsan svejsan\n";
    char rbuf[50];

    /* Öppna filen "minfil" i läs- och skrivläge (O_RDWR).
       Skapa den om den inte redan finns (O_CREAT) 
       Sätt filrättigheterna till 00644*/
    fd = open("minfil", O_CREAT|O_RDWR, 00644);
    write(fd, wbuf, sizeof(wbuf)); /* Skriv wbuf till filen */

    /* Här börjar vi läsa in filen igen */
    fstat(fd, &fileinfo);
    filesize = fileinfo.st_size;
    printf("Storlek: %ld\n", (long int)filesize);
    /* Återställ markören till byte 0 med lseek */
    lseek(fd, 0, SEEK_SET);
    readstat = read(fd, rbuf, filesize);  /* Läs innehållet till rbuf */
    rbuf[fileinfo.st_size+1] = '\0';  /* Avsluta med NULL */

    /* Skriv ut information och filens innehåll */
    printf("Fildeskriptorns nummer: %d\n", fd);
    printf("Returvärde från 'read': %d\n", readstat);
    printf("Inläst text: %s\n", rbuf);

    return 0;
}
