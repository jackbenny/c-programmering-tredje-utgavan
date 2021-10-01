#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#define MAXSIZE 100

int main(int argc, char *argv[])
{
   struct addrinfo hints, *res, *result;
   char addrstr[MAXSIZE];
   char host[MAXSIZE];
   void *ptr;

   /* argument till programmet */
   if (argc == 2)
   {
      strncpy(host, argv[1], MAXSIZE);   
   }
   else
   {
      printf("Please specify a host to lookup\n");
      return 1;
   }

   memset (&hints, 0, sizeof (hints)); /* nolla ut hints */
   hints.ai_family = AF_UNSPEC; /* både IPv4 och IPv6 */
   hints.ai_socktype = SOCK_STREAM;

   /* hämta IP */
   if ( getaddrinfo (host, NULL, &hints, &result) != 0 )
   {
      perror ("getaddrinfo");
      return 1;
   }

   res = result;

   while (res) /* loopa över alla IP-adresser */
   {
      switch (res->ai_family) /* IPv4 eller IPv6 */
      {
         case AF_INET: /* IPv4 */
            ptr = &((struct sockaddr_in *) res->ai_addr)->sin_addr;
            break;
         case AF_INET6: /* IPv6 */
            ptr = &((struct sockaddr_in6 *) res->ai_addr)->sin6_addr;
            break;
      }
      /* omvandla binär-IP till läslig IP-adress */
      inet_ntop (res->ai_family, ptr, addrstr, MAXSIZE);
      printf ("%s\n", addrstr);
      res = res->ai_next; /* nästa IP i listan */
   }
   freeaddrinfo(result); /* frigör minnet */
   return 0;
}
