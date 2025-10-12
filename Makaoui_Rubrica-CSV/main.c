#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Autore: Makaoui Youness
 * Data: 12/10/2025
 * Classe: 4G
 * Luogo: Lab 53bis
 * Descrizione: Rubrica infinita
                ** funzioni sperimentali in searchNumber, prof ho fatto robe
                * Aggiunto il salvataggio in csv
*/

// record Contatto
struct Contatto{

    char name[50];
    char surname[50];
    char telephone[20];
    char city[50];
    char address[50];
    struct Contatto *next;

}Contatto;

// salva i dati in un file csv, solo scrittura
void LoadData ( struct Contatto ** rubricaHead ) {

    if ( rubricaHead == NULL )
        return;

    FILE *pointRubrica = fopen("Data.csv","w+");

    struct Contatto *tmp = *rubricaHead;

    while ( tmp != NULL ) {
        fprintf( pointRubrica, "%s,%s,%s,%s,%s,",
            tmp->name, tmp->surname, tmp->telephone, tmp->city, tmp->address
            );
        tmp = tmp->next;
    }

    // avevo dimenticato
    fclose( pointRubrica );
    printf("\n\n-- Salvato -- \n\n");
}

// stampa rubrica
void PrintContacts ( struct Contatto ** );
// crea un nodo Contatto
struct Contatto *CreateContact ();
// inserimento in testa
int InsertContactHead ( struct Contatto ** );
// inserimento in coda
int InsertContactTail ( struct Contatto ** );
// cerca il contatto e restituisce quello precedente se esiste
struct Contatto *SearchNumber ( struct Contatto ** );
// cerca ed elimina il contatto
void DeleteContact ( struct Contatto ** );


int main () {

    struct Contatto *rubricaHead = NULL;
    int choice;

    do {
        printf("\n1 - Inserisci in testa");
        printf("\n2 - Inserisci in coda");
        printf("\n3 - Trova numero");
        printf("\n4 - Elimina contatto");
        printf("\n5 - Stampa rubrica");
        printf("\n6 - Salvataggio");
        printf("\n7 - Esci\n: ");
        scanf("%d",&choice);
        fflush(stdin);

        switch (choice) {
            case 1:
                if ( InsertContactHead( &rubricaHead ) == 1 ) {
                    printf("\nContatto inserito");
                } else {
                    printf("\nErrore Allocazione");
                }
                break;

            case 2:
                if ( InsertContactTail( &rubricaHead ) == 1 ) {
                    printf("\nContatto inserito");
                } else {
                    printf("\nErrore Allocazione");
                }
                break;

            case 3:
                SearchNumber( &rubricaHead );
                break;

            case 4:
                DeleteContact ( &rubricaHead );
                break;

            case 5:
                if ( rubricaHead != NULL )
                    PrintContacts( &rubricaHead );
                else
                    printf("\n\n-- Rubrica Vuota -- \n\n");
                break;

            case 6:
                if ( rubricaHead != NULL )
                    LoadData( &rubricaHead );
                else
                    printf("\n\n-- Rubrica Vuota -- \n\n");
                break;

            case 7:
                printf("\nesci");
                break;

            default:
                printf("\nErrore imprevisto");
                break;
        }
    }while(choice != 7);

    return 0;
}


// crea un nodo Contatto
struct Contatto *CreateContact () {

    struct Contatto *newContatto = (struct Contatto *)malloc(sizeof(struct Contatto));

    printf("\nInserisci nome: ");
    scanf("%s",newContatto->name);
    fflush(stdin);
    printf("\nInserisci cognome: ");
    scanf("%s",newContatto->surname);
    fflush(stdin);
    printf("\nInserisci il numero: ");
    scanf("%s",newContatto->telephone);
    fflush(stdin);
    printf("\nInserisci la citta: ");
    scanf("%s",newContatto->city);
    fflush(stdin);
    printf("\nInserisci l'indirizzo: ");
    scanf("%[^\n]s",newContatto->address);
    fflush(stdin);

    newContatto->next = NULL;

    return newContatto;
}

// stampa rubrica
void PrintContacts ( struct Contatto **head ) {

    struct Contatto *current = *head;
    printf("\n\n-- Inizio Rubrica --\n");
    while ( current != NULL )
    {
        printf("\nNome: %s", current->name);
        printf("\nCognome: %s", current->surname);
        printf("\nNumero: %s", current->telephone);
        printf("\nCitta: %s", current->city);
        printf("\nIndirizzo: %s", current->address);
        current = current->next;
    }
    printf("\n\n-- Fine Rubrica --\n\n");
}

// inserimento in testa
int InsertContactHead ( struct Contatto **head ) {

    // se la lista e vuota
    if ( *head == NULL ) {
        *head = CreateContact ();
        return 1;
    }

    struct Contatto* newNode = CreateContact ();

    if ( newNode == NULL )
        return 0;

    newNode->next = *head;
    *head = newNode;
    return 1;
}

// inserimento in coda
int InsertContactTail ( struct Contatto **head ) {

    // caso in cui la lista sia vuota
    if ( head == NULL ){
        return InsertContactHead( head );
    }

    struct Contatto* current = *head;
    // arrivo alla coda
    while ( current->next != NULL )
    {
        current = current->next;
    }

    // aggiungo
    struct Contatto *newContact = CreateContact();
    newContact->next = NULL;
    current->next = newContact;
    return 1;
}

// cerca il contatto e restituisce quello precedente se esiste
struct Contatto *SearchNumber ( struct Contatto **head) {

    if ( head == NULL )
        return NULL;

    char number[20];
    printf("\nInserisci il numero ESATTO: ");
    scanf("%s",number);
    fflush(stdin);

    struct Contatto* current = *head;
    struct Contatto* previous = NULL;

    while ( current != NULL ) {

        if ( strcmp( number, current->telephone ) == 0 ) {
            // free(current); -- mio errore :(
            printf("\n--Contatto trovato--\n");
            printf("\nNome: %s", current->name);
            printf("\nCognome: %s", current->surname);
            printf("\nNumero: %s", current->telephone);
            printf("\nCitta: %s", current->city);
            printf("\nIndirizzo: %s\n", current->address);
            return previous;
        }
        previous = current;
        current = current->next;

    }

    // non ho trovato nulla
    return NULL;
}

// cerca ed elimina il contatto
void DeleteContact ( struct Contatto **head ) {

    if ( *head == NULL )
        return;

    struct Contatto *previous = SearchNumber( head );

    printf("\n-- Eliminato --\n");
    // caso in cui esiste solo la testa
    if ( previous == NULL ) {
        *head = NULL;
        return;
    }

    struct Contatto *current = previous->next;
    previous->next = current->next;
    free(current);
}