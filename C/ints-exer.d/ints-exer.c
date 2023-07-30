#include <stdio.h>
int main(){
    //declaring variables
    int myNum;

    //assign a value
    myNum = 15;
    //to print you must use a format specifier
    printf("%d\n", myNum);

    //or declare and assign
    int newNum = 35;
    float newFloat = 3.14;
    //USE SINGLE QUOTES
    char newChar = 'C';

    printf("%i\n", newNum);
    printf("%f\n", newFloat);
    printf("%c\n", newChar);

    //using numbers within print statements
    printf("My favorite number is %i and my favorite letter is %c.\n", newNum, newChar);
}
