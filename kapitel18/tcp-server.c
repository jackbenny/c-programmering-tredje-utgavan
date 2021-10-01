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
int datafd;

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
	if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0 ) 
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
    signal(SIGPIPE, cleanUp); /* när klienten kopplar från servern
                                 får den en SIGPIPE */

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
		perror("bind"); 
		return 1; 
	} 

    /* lyssna efter inkommande anslutningar */
    if ( (listen(sockfd, 5)) != 0 ) 
    {
        perror("listen");
        return 1;
    }
    else
    {
        printf("Server listening...\n");
    }
	len = sizeof(cliaddr); /* storleken på adressen */

    /* acceptera inkommande anslutning */
    datafd = accept(sockfd, (struct sockaddr *)&cliaddr, &len);
    if (datafd < 0) 
    {
        perror("accept");
        return 1;
    }
    else
    {
        printf("Server accepted connection...\n");
    }

    /* ta emot paket och loopa tills klienten kopplar från */
    while(1)
    {
        n = read(datafd, buffer, sizeof(buffer));
        /* skriv ut meddelandet vi tog emot från klienten och 
           skicka en bekräftelse */
        buffer[n] = '\0'; /* avsluta strängen med null */
        printf("Client: %s\n", buffer); 
        write(datafd, confirmation, strlen(confirmation)+1);
        printf("Confirmation message sent to client\n"); 
    }
    /* vi når aldrig hit - men fall i fall */
	close(sockfd);
    close(datafd);
	return 0; 
}

void cleanUp(int signum)
{
    printf("Quitting gracefully and closing the socket\n");
    close(sockfd);
    close(datafd);
    exit(0);
}
