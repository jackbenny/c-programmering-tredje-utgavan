#define _XOPEN_SOURCE 500
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define MAX 100

int main(void)
{
    /* Struktur som krävs av msgsnd & msgrcv */
    struct msgbuf
    {
        long mtype;
        char mtext[MAX];
    };

    int id;
    key_t key = 12345;
    struct msgbuf msg;
    msg.mtext[0] = '\0';
    
    /* Kalla msgget för att få ett ID-nummer till kön.
       Observera att vi här utelämnar IPC_CREAT. */
    if ( (id = msgget(key, 0660)) < 0 )
    {
        fprintf(stderr, "Could not open message queue\n");
        perror("msgget");
        return 1;
    }

    /* Ta emot meddelandet och spara det i msg */
    if ( msgrcv(id, &msg, MAX, 1, 0) < 0 )
    {
        fprintf(stderr, "Could not receive messages\n");
        perror("msgrcv");
        return 1;
    }

    /* Skriv ut meddelandet */
    printf("%s\n", msg.mtext);

    return 0;
}
