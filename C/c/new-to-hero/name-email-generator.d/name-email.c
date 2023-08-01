#include<stdio.h>
#include<string.h> //include the string library.

void generateEmail(const char* firstName, const char* lastName, char* emailAddr);

int main(){
    char firstName[50];
    char lastName[50];
    char emailAddr[100];
    scanf("%49s", firstName);
    scanf("%49s", lastName);

    generateEmail(firstName, lastName, emailAddr);

    printf("Your email address is: %s\n", emailAddr);
    return 0;
}

void generateEmail(const char* firstName, const char* lastName, char* emailAddr){
    strcpy(emailAddr, firstName);
    strcat(emailAddr, ".");
    strcat(emailAddr, lastName);
    strcat(emailAddr, "@mybutt.com");

}
