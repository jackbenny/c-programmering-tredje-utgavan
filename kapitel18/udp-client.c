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
	char message[MAXLINE];
    struct sockaddr_in servaddr;
    int n;
    socklen_t len; 

	/* skapa socket-filen */
	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) 
    { 
		perror("socket creation failed"); 
		return 1; 
	} 

    /* kontrollera om vi angav en adress */
    if (argc == 2)
    {
        strncpy(ipaddr, argv[1], SIZE-1);
    }

    /* registrera signalhanterarna */
    signal(SIGTERM, cleanUp);
    signal(SIGABRT, cleanUp);
    signal(SIGQUIT, cleanUp);
    signal(SIGINT, cleanUp);

    /* nolla ut strukturen med adressen */
	memset(&servaddr, 0, sizeof(servaddr)); 

	/* information om IP-adress och port */
	servaddr.sin_family = AF_INET; /* IPv4 */
	servaddr.sin_port = htons(port); 
	servaddr.sin_addr.s_addr = inet_addr(ipaddr);; 

    len = sizeof(servaddr); /* storleken på adressen */

    /* läs meddelanden och skicka till servern */
    while(1)
    {
        printf("Type your message: ");
        fgets(message, sizeof(message), stdin);
        /* byt ut radbrytningstecknet mot null */
        message[strcspn(message, "\n")] = '\0';
        /* skicka meddelandandet till servern med 'sendto' */
        sendto(sockfd, (const char *)message, strlen(message), 
            0, (const struct sockaddr *) &servaddr, len); 

        /* ta emot meddelande från servern med 'recvfrom' */
        n = recvfrom(sockfd, (char *)buffer, MAXLINE, 
                    MSG_WAITALL, (struct sockaddr *) &servaddr, &len); 
        buffer[n] = '\0'; /* avsluta strängen med null */

        /* skriv ut svaret från servern */
        printf("Server: %s\n", buffer); 
    }
    /* vi når aldrig hit - men fall i fall */
	close(sockfd); 
	return 0; 
}

void cleanUp(int signum)
{
    printf("\nQuitting gracefully and closing the socket\n");
    close(sockfd);
    exit(0);
}
