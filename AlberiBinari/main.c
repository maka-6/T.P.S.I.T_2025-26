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
void SearchContact ( Node *, struct contatto );
// cerca ed elimina il nodo
void DeleteNode ( Node * );


int main () {

    Node *root = NULL;
    int choice;

    do {
        printf("\n1 - Inserisci un nuovo contatto");
        printf("\n2 - Stampa tutta la rubrica in ordine");
        printf("\n3 - Trova un contatto");
        printf("\n4 - Elimina un contatto");
        printf("\n5 - Statistiche Albero");
        printf("\n6 - Min e Max");
        printf("\n7 - Esci\n: ");
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
                if ( root != NULL ) {
                    printf("\n\n-- Inizio Rubrica --\n");
                    PrintNodes( root );
                    printf("\n\n-- Fine Rubrica --\n\n");

                } else
                    printf("\n\n-- Rubrica Vuota -- \n\n");
                break;

            case 3:
                printf("\nInserisci nome e cognome del contatto da cercare: ");
                struct contatto target = compileContact();
                SearchContact( root, target );
                break;

            case 4:
                DeleteNode ( root );
                break;

            case 5:
                break;

            case 6:
                break;

            case 7:
                printf("\nesci");
                break;

            default:
                printf("\nErrore imprevisto");
                break;
        }
    }while(choice!=7);

    return 0;
}

// compila un utente
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
// stampa un contatto
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
void PrintNodes(Node *root) {
    if (root == NULL)
        return;

    PrintNodes(root->sx);
    printContact(root->contatto);
    PrintNodes(root->dx);
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
void SearchContact(Node *root, struct contatto target) {
    if (root == NULL) {
        printf("\n--Contatto non trovato--\n");
        return;
    }

    int cmp = strcmp(target.surname, root->contatto.surname);
    if (cmp == 0)
        cmp = strcmp(target.name, root->contatto.name);

    if (cmp == 0) {
        printf("\n--Contatto trovato--\n");
        printContact(root->contatto);
    } else if (cmp < 0) {
        SearchContact(root->sx, target);
    } else {
        SearchContact(root->dx, target);
    }
}

// cerca ed elimina il contatto
void DeleteNode ( Node *root ) {

    if ( root == NULL )
        return;

    printf("\n-- Eliminato --\n");
    // caso in cui esiste solo la testa

}