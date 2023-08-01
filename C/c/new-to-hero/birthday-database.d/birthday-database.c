#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//data structure for holding the birthday data
typedef struct birthday_database {
    char* date;
    char* name;
    struct birthday_database* next;
} birthday_database;

//add name and date to the 'linked list'
void add_birthday(birthday_database** head, const char* name, const char* date){
    birthday_database* newBirthday = (birthday_database*)malloc(sizeof(birthday_database));
    newBirthday->name = strdup(name);
    newBirthday->date = strdup(date);
    newBirthday->next = *head;
    *head = newBirthday;
}

//find a birthday in our 'Linked list'
int find_birthday(birthday_database* head, const char* name, const char* date){
    birthday_database* current = head;
    while(current != NULL){
        if (strcmp(current->name, name) == 0 && strcmp(current->date, date) == 0){
            return 1; //Name and date was in the list
        }
        current = current->next;
    }
    return 0; //Name and date not in the list
}

void free_birthday(birthday_database* head){
    birthday_database* current = head;
    while (current != NULL){
        birthday_database* temp = current;
        current = current->next;
        free(temp->name);
        free(temp->date);
        free(temp);
    }
}

int main(){
    birthday_database* head = NULL;

    while(1){
        char name[100];
        char date[100];

        printf("Enter a name: ");
        scanf("%99s", name);

        printf("Enter birthday date: ");
        scanf("%99s", date);

        if (find_birthday(head, name, date)){
            printf("Name already exists: %s\n", name);

        } else {
            add_birthday(&head, name, date);
        }
    }

    free_birthday(head);

    return 0;
}
