#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30
#define MATR 5

// record data
struct date {
    int day;
    int month;
    int year;
};

// record studente
typedef struct studente {
    char matricola[MATR];
    char name[MAX];
    char surname[MAX];
    char class[MAX];
    float median;
    struct date birthdate;
    struct studente *pointNext;
}Studente;


int addStudent(Studente **head);
void showStudents(Studente **head);
Studente *searchStudent(Studente **head);
int deleteStudent(Studente **head);
float calculateMedian(Studente **head);

int main(void) {
    int choice;
    Studente *head = NULL;
    do {
        printf("\n 1 - Aggiungi studente");
        printf("\n 2 - Visualizza registro studenti");
        printf("\n 3 - Cerca studente");
        printf("\n 4 - Rimuovi studente");
        printf("\n 5 - Calcola media voti");
        printf("\n 6 - Esci\n:");
        scanf("%d", &choice);
        fflush(stdin);
        
        switch (choice) {
            case 1:
                if ( addStudent(&head) == 0 )
                    printf("Studente aggiunto con successo!\n");
                else
                    printf("Errore nell'aggiunta dello studente!\n");
                break;

            case 2:
                showStudents(&head);
                break;

            case 3:
                if ( searchStudent(&head) != NULL )
                    printf("Studente trovato!\n");
                else
                    printf("Studente non trovato!\n");
                break;

            case 4:
                deleteStudent(&head);
                break;

            case 5:
                printf("\nMedia voti: %.2f",calculateMedian(&head));
                break;

            case 6:
                printf("Bye!\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    }while (choice != 6);
}

Studente *compileStudent() {

    Studente *newStudent = malloc(sizeof(Studente));
    printf("Inserisci matricola: ");
    scanf("%s", newStudent->matricola);
    fflush(stdin);

    printf("Inserisci nome: ");
    scanf("%s", newStudent->name);
    fflush(stdin);

    printf("Inserisci cognome: ");
    scanf("%s", newStudent->surname);
    fflush(stdin);

    printf("Inserisci classe: ");
    scanf("%s", newStudent->class);
    fflush(stdin);

    printf("Inserisci data di nascita x/x/x: ");
    scanf("%d/%d/%d", &newStudent->birthdate.day, &newStudent->birthdate.month, &newStudent->birthdate.year);
    fflush(stdin);

    printf("Inserisci media: ");
    scanf("%f", &newStudent->median);
    fflush(stdin);

    newStudent->pointNext = NULL;

    return newStudent;
}

int addStudent(Studente **head) {

    Studente *newStudent = compileStudent();

    if ( newStudent == NULL ) {
        return 1;
    }

    if ( *head == NULL ) {
        *head = newStudent;
        newStudent->pointNext = NULL;
    }

    Studente *temp = *head;
    while ( temp->pointNext != NULL ) {
        temp = temp->pointNext;
    }
    temp->pointNext = newStudent;
    newStudent->pointNext = NULL;

    return 0;
}

void showStudents(Studente **head) {

    if ( *head == NULL ) {
        return;
    }
    Studente *temp = *head;
    while ( temp != NULL ) {
        printf("Matricola: %s\nNome: %s\nCognome: %s\nClasse: %s\nData di nascita: %d/%d/%d\nMedia: %.2f\n", temp->matricola, temp->name, temp->surname, temp->class, temp->birthdate.day, temp->birthdate.month, temp->birthdate.year, temp->median);
        temp = temp->pointNext;
    }
}

Studente *searchStudent(Studente **head) {
    if ( *head == NULL ) {
        return NULL;
    }
    Studente *temp = *head;
    char matricola[MATR];
    printf("Inserisci matricola: ");
    scanf("%s", matricola);
    fflush(stdin);
    while ( temp != NULL ) {
        if ( strcmp(temp->matricola, matricola) == 0 ) {
            return temp;
        }
        temp = temp->pointNext;
    }
    showStudents(&temp);
}

int deleteStudent(Studente **head) {
    if ( *head == NULL ) {
        return 1;
    }
    Studente *temp = *head;
    char matricola[MATR];

    printf("Inserisci matricola: ");
    scanf("%s", matricola);
    fflush(stdin);
    if ( temp->pointNext == NULL ) {
        if ( strcmp(temp->matricola, matricola) == 0 ) {
            free(temp);
            *head = NULL;
            return 0;
        }
    }
    while ( temp->pointNext != NULL ) {
        if ( strcmp(temp->pointNext->matricola, matricola) == 0 ) {
            Studente *toDelete = temp->pointNext;
            temp->pointNext = toDelete->pointNext;
            free(toDelete);
            return 0;
        }
        temp = temp->pointNext;
    }

    return 1;
}

float calculateMedian(Studente **head) {
    if ( *head == NULL ) {
        return 0;
    }

    int nStudenti = 0;
    float sommaVoti = 0;

    Studente *temp = *head;

    while ( temp != NULL ) {
        nStudenti++;
        sommaVoti += temp->median;
        temp = temp->pointNext;
    }

    return sommaVoti / (float)nStudenti;
}