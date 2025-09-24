#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int num;
    struct Node *next;
}Node;

void PrintList ( Node** );
void InsertNodeHead ( Node**, int );
void InsertNodeTail ( Node**, int );

int main(void) {

    printf("Hello, World!\n");

    // testa della lista
    Node *head ;

    InsertNodeHead ( &head, 5 );
    InsertNodeHead ( &head, 6 );
    InsertNodeTail ( &head, 7 );
    InsertNodeTail ( &head, 8 );
    InsertNodeHead ( &head, 9 );
    PrintList ( &head );

    return 0;
}

void PrintList ( Node** head ) {

    if ( head == NULL )
        return;

    Node *current = *head;

    while ( current != NULL )
    {
        printf("%d ", current->num);
        current = current->next;
    }

}

void InsertNodeHead ( Node** head, int value ) {

    Node* newNode = (Node *)malloc(sizeof(Node));
    newNode->num = value;
    newNode->next = *head;
    *head = newNode;

}

void InsertNodeTail ( Node** head, int value ) {

    // caso in cui la lista sia vuota
    if ( head == NULL )
    {
        InsertNodeHead ( head, value );
        return;
    }

    Node* newNode = (Node *)malloc(sizeof(Node));
    Node* current = *head;

    // arrivo alla coda
    while ( current->next != NULL )
    {
        current = current->next;
    }

    // aggiungo
    newNode->num = value;
    newNode->next = NULL;
    current->next = newNode;

}