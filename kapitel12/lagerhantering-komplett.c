#define _XOPEN_SOURCE 500
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* Makron */
#define NAMEMAXLENGTH 30

/* Globala variabler så att de är tillgängliga både
   från main() och de övriga funktionerna.
   struct myData används t.ex. både från main() och
   new() */
struct myData
{
    char name[NAMEMAXLENGTH];
    int quantity;
    float price;
};

char filename[] = "storage.bin";

/* Funktionsprototyper */
void list(struct myData *datap, int numRec);
void search(struct myData *datap, int numRec, char *name);
void modify(struct myData *datap, int numRec, char *name);
void delete(struct myData *datap, int numRec, char *name);
int new(struct myData *datap);
void printUsage(char *arg);
void printHeader(void);


int main(int argc, char* argv[])
{
    FILE *fp;   /* Filpekare */
    int newart = 0; /* Ska vi skapa en ny artikel? */
    int numRec; /* För antalet för artiklar */
    int create; /* För y/n-fråga */
    int opt;    /* För getopt() */

    /* Skapa en strukturvariabel (en pekare) av struct myData */
    struct myData *data;

    /* Skriv ut hjälptexten och returnera 1 om vi saknar argument */
    if (argc < 2)
    {
        printUsage(argv[0]);
        return 1;
    }
    
    /* Kontrollera om filen finns och är läs- och skrivbar.
       Om inte, fråga om vi ska skapa den och börja läsa 
       in artiklar. access() är ett systemanrop för Unixmiljöer */
    if ( access(filename, R_OK|W_OK) != 0 )
    {
        /* Använd fprintf() för att skriva felmeddelanden 
           till stderr */
        fprintf(stderr, "Could not open %s\n", filename);
        printf("Create the file and start adding records? (y/n): ");
        create = getchar();
        if ( create == 'y' )
        {
            /* Allokera minne för en struct myData och anropa
               sedan new() med en pekare till minnet för att lägga
               till artiklar i lagret, en i taget */
            numRec = 1;
            data = calloc(numRec, sizeof(struct myData));
            new(data);
            free(data);
            return 0;
        }
        else
            return 1;
    }

    /* Öppna filen i läsläge */
    fp = fopen(filename, "rb");

    /* Läs in befintlig data från filen till strukturen */
    fseek(fp, 0, SEEK_END);
    numRec = ftell(fp) / sizeof(struct myData);
    data = calloc(numRec, sizeof(struct myData));
    rewind(fp);
    fread(data, sizeof(struct myData), numRec, fp);
    fclose(fp);

    /* Behandla argumenten med getopt() */
    while ((opt = getopt(argc, argv, "hls:m:d:n")) != -1)
    {
        switch (opt)
        {
        case 'l':
            list(data, numRec);
            break;
        case 's':
            search(data, numRec, optarg);
            break;
        case 'm':
            modify(data, numRec, optarg);
            break;
        case 'd':
            delete(data, numRec, optarg);
            break;
        case 'n':
            newart = 1;
            break;
        case 'h':
            printUsage(argv[0]);
            return 0;
        default:
            printUsage(argv[0]);
            return 1;
        }
    }
    
    /* Fortsätt här om filen finns och vi valde att lägga 
       till artiklar */ 
    if ( newart == 1 )
    {
        data = calloc(1, sizeof(struct myData));
        if ( new(data) == 1 )
            return 1;
    }

    /* Här är programmet klart, så frigör minnet och returnera 0 */
    free(data);
    return 0;
}

/* Funktionerna nedan tar en pekare till datatypen struct myData
   som första argument. Som andra argument ett heltal som innehåller
   antalet artiklar i lagret. */
void list(struct myData *datap, int numRec)
{
    int i;
    printHeader();
    for (i = 0; i<numRec; i++)
    {
        printf("%-30s\t", datap[i].name);
        printf("%-10d\t", datap[i].quantity);
        printf("%.2f\t", datap[i].price);
        printf("\n");
    }
    printf("\n");
}

/* Det tredje argumentet till denna funktionen är en pekare till char
   som används för att söka efter en artikel. */
void search(struct myData *datap, int numRec, char *name)
{
    int i;
    /* Loopa över alla artiklar i databasen */
    for (i = 0; i<numRec; i++)
    {
        /* Om ingen match finns, hoppa över och fortsätt
           till nästa */
        if ( strcmp(name, datap[i].name) != 0 )
            continue;
        printHeader();
        printf("%-30s\t", datap[i].name);
        printf("%-10d\t", datap[i].quantity);
        printf("%.2f\t", datap[i].price);
        printf("\n");   
    }
}

/* Samma argument som för search-funktionen */
void modify(struct myData *datap, int numRec, char *name)
{
    FILE *newfp; /* Ny filpekare för denna funktion */
    int i;
    int match = 0;
    char what[10];
    char quant[20];

    /* Loopa över alla artiklar i lagret */
    for (i = 0; i<numRec; i++)
    {
        if ( strcmp(name, datap[i].name) == 0 )
        {
            match = 1; /* Så att vi vet om vi hittade artikeln
                          när vi kommer utanför if-satsen */
            printHeader();
            printf("%-30s\t", datap[i].name);
            printf("%-10d\t", datap[i].quantity);
            printf("%.2f\t", datap[i].price);
            printf("\n\n");    

            printf("What do you like to modify? "
                   "(name, quantity, price): ");
            fgets(what, 10, stdin);
            what[strcspn(what, "\n")] = '\0';

            if ( strcmp(what, "name") == 0 )
            {
                printf("Name: ");
                fgets(datap[i].name, NAMEMAXLENGTH, stdin);
                datap[i].name[strcspn(datap[i].name, "\n")] = '\0';
            }
            else if ( strcmp(what, "quantity") == 0 )
            {
                printf("Quantity (absolute value or "
                       "(a)dd/(s)ubtractNUMBER): ");
                fgets(quant, 20, stdin);
                quant[strcspn(quant, "\n")] = '\0';
                
                /* Behandla det första tecknet som angavs */
                if (quant[0] == 'a') /* a för add */
                {
                    quant[0] = ' '; /* Radera det första tecknet */
                    datap[i].quantity = datap[i].quantity +
                        atoi(quant);
                }
                else if (quant[0] == 's') /* s för subtract */
                {
                    quant[0] = ' ';
                    datap[i].quantity = datap[i].quantity -
                        atoi(quant);
                }
                else
                    datap[i].quantity = atoi(quant);
                
            }
            else if ( strcmp(what, "price") == 0 )
            {
                printf("Price: "); scanf("%f", &datap[i].price);
            } 
        }
    }
    if (match == 0)
    {
        fprintf(stderr, "Could not find %s in database\n", name);
        exit(1);
    }
    /* Öppna filen i skrivläge och skriv ut den modifierade 
       strukturen till filen */
    if ( (newfp = fopen(filename, "wb")) == 0 )
    {
        fprintf(stderr, "Could not open file for writing\n");
        exit(1);
    }
    fwrite(datap, sizeof(struct myData), numRec, newfp);
    fclose(newfp);
}

void delete(struct myData *datap, int numRec, char *name)
{
    int i, j; /* För for-looparna */
    int match = 0;
    FILE *newfp; /* Ny filpekare för denna funktion */
    int answer;

    /* Look/sök igenom hela databasen */
    for (i = 0; i<numRec; i++)
    {
        if ( strcmp(name, datap[i].name) == 0 )
        {
            /* Sätt match till 1 så att vi inte skriver ut
               om det inte finns någon match längre fram */
            match = 1;
            printHeader();
            printf("%-30s\t", datap[i].name);
            printf("%-10d\t", datap[i].quantity);
            printf("%.2f\t", datap[i].price);
            printf("\n\n");
            printf("Delete the record listed above? (y/n): ");
            
            answer = getchar();
            if ( answer == 'y' )
            {
                if ( (newfp = fopen(filename, "wb")) == 0 )
                {
                    fprintf(stderr,
                            "Could not open file for writing\n");
                    exit(1);
                }
                /* Loopa igenom alla artiklar i databasen och skriv 
                   ut dem till filen igen, FÖRUTOM de som matchar 
                   sökordet */
                for (j = 0; j<numRec; j++)
                {
                    if ( strcmp(name, datap[j].name) == 0 )
                        continue;
                    fwrite(&datap[j], sizeof(struct myData), 1,
                           newfp);
                }
                fclose(newfp);
            }
        }
    }
    if (match == 0)
    {
        fprintf(stderr, "Could not find %s in database\n", name);
        exit(1);
    }
}

int new(struct myData *datap)
{
    FILE *fp;
    int bytes;
    if ( (fp = fopen(filename, "ab")) == 0 )
    {
        fprintf(stderr, "Could not open file for writing\n");
        return 1;
    }

    /* Fråga efter uppgifterna för varje ny artikel och skriv ut
       artiklarna, en efter en till filen. Loopa tills användaren
       skriver 'done' som namn. */
    for (;;)
    {
        /* Sätt stdin-bufferten till NULL efter varje iteration
           (för att tömma bufferten) */
        setbuf(stdin, NULL);
        printf("Name ('done' when finished): ");
        fgets(datap->name, NAMEMAXLENGTH, stdin);
        datap->name[strcspn(datap->name, "\n")] = '\0';
        
        if ( strcmp(datap->name, "done") == 0 )
        {
            fclose(fp);
            return 0;
        }
        printf("Quantity: "); scanf("%d", &datap->quantity);
        printf("Price: "); scanf("%f", &datap->price);
        bytes = fwrite(datap, sizeof(struct myData), 1, fp);
        if (bytes != 1)
        {
            fprintf(stderr, "Could not write to the file!\n");
            return 1;
        }
    }
}

void printUsage(char *arg)
{
    fprintf(stderr, "Usage: %s [-l] [-s name] "
            "[-m name] \n" 
            "[-d name] [-n] [-h]\n\n"
        "-l      = list the articles in the database\n"
        "-s name = search for an article named 'name'\n"
        "-m name = modify the article named 'name'\n"
        "     You'll then have the choice to change name, quantity "
            "and price.\n"
        "-d name = delete the article named 'name'\n"
        "-n      = create new articles (interactive mode only)\n"
        "-h      = display this help message\n", arg);
}

void printHeader(void)
{
    int i;
    printf("\n%-30s\t", "Name");
    printf("%s\t", "Quantity");
    printf("%s\t\n", "Price");
    for (i = 0; i<=52; i++)
        printf("=");
    printf("\n");
}
