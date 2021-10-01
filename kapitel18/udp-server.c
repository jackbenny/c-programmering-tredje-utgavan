#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
#include <signal.h>

#define MAXLINE 1024
#define SIZE 20
int sockfd;

void cleanUp(int signum);

int main(int argc, char* argv[])
{
    char ipaddr[SIZE] = "127.0.0.1";
    int port = 9000; 
	char buffer[MAXLINE]; 
	char *confirmation = "Message received"; 
    struct sockaddr_in servaddr, cliaddr;
    int n;
    socklen_t len;

	/* skapa socket */
	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) 
    { 
		perror("socket creation failed"); 
		return 1; 
	} 

    /* kontrollera om vi angav en lyssnar-adress */
    if (argc == 2)
    {
        strncpy(ipaddr, argv[1], SIZE-1);
    }

    /* registrera signalhanterarna */
    signal(SIGTERM, cleanUp);
    signal(SIGABRT, cleanUp);
    signal(SIGQUIT, cleanUp);
    signal(SIGINT, cleanUp);

    /* nolla adress-strukturerna innan vi använder dem */
	memset(&servaddr, 0, sizeof(servaddr)); 
	memset(&cliaddr, 0, sizeof(cliaddr)); 

	/* information om IP-adress och port */ 
	servaddr.sin_family = AF_INET; /* IPv4 */
	servaddr.sin_addr.s_addr = inet_addr(ipaddr); 
	servaddr.sin_port = htons(port); 

	/* knyt ihop vår socket med adressen */
	if ( bind(sockfd, (const struct sockaddr *)&servaddr, 
			sizeof(servaddr)) < 0 ) 
	{ 
		perror("bind failed"); 
		return 1;
	} 
	len = sizeof(cliaddr); /* storleken på adressen */

    /* ta emot udp-paket och loopa för evigt */
    while(1)
    {
        n = recvfrom(sockfd, (char *)buffer, MAXLINE, 
                    MSG_WAITALL, ( struct sockaddr *) &cliaddr, 
                    &len);
        buffer[n] = '\0'; /* avsluta strängen med null */

        /* skriv ut meddelandet vi tog emot från klienten och skicka en
           bekräftelse */
        printf("Client: %s\n", buffer); 
        sendto(sockfd, (const char *)confirmation, 
            strlen(confirmation), 0, 
            (const struct sockaddr *) &cliaddr, len);
        printf("Confirmation message sent to client\n"); 
    }
    /* vi når aldrig hit - men fall i fall */
	close(sockfd);
	return 0; 
}

void cleanUp(int signum)
{
    printf("Quitting gracefully and closing the socket\n");
    close(sockfd);
    exit(0);
}
