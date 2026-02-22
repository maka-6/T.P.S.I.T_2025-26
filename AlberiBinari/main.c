#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Autore: Makaoui Youness
 * Data: 22/02/2026
 * Classe: 4G
 * Luogo: xx
 * Descrizione: Alberi binari
*/

// record Contatto
struct contatto{
    char name[50];
    char surname[50];
    char telephone[20];
};

typedef struct node {
    struct contatto contatto;
    struct node *dx;
    struct node *sx;
}Node;


struct contatto compileContact ();
// stampa rubrica
void PrintNodes ( Node * );
// crea un nodo Contatto
Node *CreateNode ();
// inserimento in testa
Node *InsertNode ( Node *, struct contatto );
// cerca il nodo e restituisce quello precedente se esiste
void SearchNumber ( Node * );
// cerca ed elimina il nodo
void DeleteNode ( Node * );


int main () {

    Node *root = NULL;
    int choice;

    do {
        printf("\n1 - Inserisci un nuovo contatto");
        printf("\n2 - Trova contatto con il numero");
        printf("\n3 - Elimina un contatto");
        printf("\n4 - Stampa tutta la rubrica");
        printf("\n5 - Esci\n: ");
        scanf("%d",&choice);
        fflush(stdin);

        switch (choice) {
            case 1:
                struct contatto newContatto = compileContact();
                if ( ( root = InsertNode( root, newContatto ) ) != NULL ) {
                    printf("\nContatto inserito");
                } else {
                    printf("\nContatto non inserito");
                    printf("\nErrore Allocazione, riprovare");
                }
                break;

            case 2:
                SearchNumber( root );
                break;

            case 3:
                DeleteNode ( root );
                break;

            case 4:
                if ( root != NULL ) {
                    printf("\n\n-- Inizio Rubrica --\n");
                    PrintNodes( root );
                    printf("\n\n-- Fine Rubrica --\n\n");

                } else
                    printf("\n\n-- Rubrica Vuota -- \n\n");
                break;

            case 5:
                printf("\nesci");
                break;

            default:
                printf("\nErrore imprevisto");
                break;
        }
    }while(choice!=5);

    return 0;
}


struct contatto compileContact () {

    struct contatto newContatto;
    printf("\nInserisci nome: ");
    scanf("%s",newContatto.name);
    fflush(stdin);
    printf("\nInserisci cognome: ");
    scanf("%s",newContatto.surname);
    fflush(stdin);
    printf("\nInserisci il numero: ");
    scanf("%s",newContatto.telephone);
    fflush(stdin);

    return newContatto;
}
void printContact ( struct contatto contatto ) {
    printf("\nNome: %s", contatto.name);
    printf("\nCognome: %s", contatto.surname);
    printf("\nNumero: %s", contatto.telephone);
}
// crea un nodo Contatto
Node *CreateNode ( struct contatto newContatto ) {

    Node *newNode = (Node *)malloc(sizeof(Node));
    if ( newNode == NULL )
        return NULL;

    newNode->contatto = newContatto;
    newNode->dx = NULL;
    newNode->sx = NULL;

    return newNode;
}

// stampa rubrica
void PrintNodes ( Node *root ) {

    Node *current = root;
    if ( root == NULL )
        return;

    printf("\nContatto: ");
    PrintNodes(current->sx);
    printContact(current->contatto);
    PrintNodes(current->dx);
}

// inserimento di un nodo
Node *InsertNode ( Node *root, struct contatto newContatto ) {
    // se la radice e vuota
    if ( root == NULL ) {
        return CreateNode(newContatto);
    }

    int cmp = strcmp( newContatto.surname, root->contatto.surname );

    if ( cmp < 0 ) {
        root->sx = InsertNode( root->sx, newContatto );

    } else if ( cmp > 0 ) {
        root->dx = InsertNode( root->dx, newContatto );

    } else {
        cmp = strcmp( newContatto.name, root->contatto.name );
        if ( cmp < 0 ){
            root->sx = InsertNode( root->sx, newContatto );

        } else if ( cmp > 0 ){
            root->dx = InsertNode( root->dx, newContatto );

        } else {
            printf("\nContatto duplicato");
        }
    }

    return root;
}

// cerca il contatto
void SearchNumber ( Node *root ) {

    if ( root == NULL )
        return;

    printf("\nInserisci i dati del contatto desiderato: ");
    struct contatto newContatto = compileContact();

    Node *current = root;

    int cmpSurname = strcmp( newContatto.surname, current->contatto.surname );
    int cmpName = strcmp( newContatto.name, current->contatto.name );

    if ( cmpSurname == 0 && cmpName == 0){
        printf("\n--Contatto trovato--\n");
        printContact(current->contatto);

    } else if ( cmpSurname < 0 ) {
        SearchNumber( current->sx );

    } else if ( cmpSurname > 0 ) {
        SearchNumber( current->dx );

    } else {
        if ( cmpName < 0 ) {
            SearchNumber( current->sx );

        } else if ( cmpName > 0 ) {
            SearchNumber( current->dx );
        }
    }
}

// cerca ed elimina il contatto
void DeleteNode ( Node *root ) {

    if ( root == NULL )
        return;

    printf("\n-- Eliminato --\n");
    // caso in cui esiste solo la testa

}