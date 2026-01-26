#include <stdio.h>

struct Birth {
    int day;
    int month;
    int year;
};

typedef struct Student {
    int matricola;
    char name[20];
    char surname[20];
    struct Birth birth;
    struct Student *pointNext;
}Student;

int main(void) {

    Student *head = NULL;
    printf("Hello, World!\n");
    return 0;
}