#include<stdio.h>

/* This program reads a full line from the console
    additionally it will hvae exercise 2-2 in it.*/

#define MAXLINE 5000

int getLine(char[], int);

int main(){
    // Use getLine to get a line from the input
    int len;
    char line[MAXLINE];

    while((len = getLine(line, MAXLINE)) != 0){
        printf("%s", line);
    }
    return 0;
}

int getLine(char line[], int limit){
    int c;
    int i = 0;
    /*original code using && and || operators
    
    for(i = 0; i < limit - 1 && (c = getchar()) != '\n' && c != EOF; ++i){
        line[i] = c;
    }

    */
    while(i < limit){
        //READ c INSIDE LOOP DUMMY!
        c = getchar();
        if(c != EOF){
            if(c != '\n'){
                line[i] = c;
                ++i;
            } else {
                //if c is newline add it, then increment and break.
                line[i] = c;
                ++i;
                break;
            }
        } else {
            //If c is EOF break out of loop
            break;
        }
    }
    line[i] = '\0';
    return i;
}