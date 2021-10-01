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

    /* Variabler vi behöver */
    int id;
    key_t key = 12345;
    struct msgbuf msg;
    size_t msglen;
    msg.mtext[0] = '\0';
    
    /* Kalla msgget för att få ett ID-nummer till kön.
       IPC_CREAT är flaggan för att skapa en kö. 0660
       är rättigheterna för kön */
    if ( (id = msgget(key, IPC_CREAT | 0660)) < 0 )
    {
        fprintf(stderr, "Could not create message queue\n");
        perror("msgget");
        return 1;
    }

    /* Komponera ett testmeddelande. mtype är till för att
       identifiera just detta meddelandet i kön. mtext är
       det faktiska innehållet och msglen är längden på
       meddelandet */
    msg.mtype = 1;
    strcat(msg.mtext, "Hejsan svejsan");
    msglen = strlen(msg.mtext) + 1;

    /* Skicka meddelandet */
    if ( msgsnd(id, &msg, msglen, IPC_NOWAIT) < 0 )
    {
        fprintf(stderr, "Could not send message\n");
        perror("msgsend");
        return 1;
    }
    
    return 0;
}
