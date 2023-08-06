#include<stdio.h>

/* This program will take in a line, pass that line to 'atoi' to convert
    the numbers that are entered from a char to an int.*/

#define MAXLINE 5000

int atoi(char s[]);
int getLine(char line[], int lenth);

int main(){
    char line[MAXLINE];
    int len;

    while((len = getLine(line, MAXLINE)) > 0){
        printf("The string is: %s", line);
        printf("The int is: %d\n", atoi(line));
    }
    return 0;
}

int getLine(char line[], int limit){
    int i, c;

    for(i = 0; i < limit - 1 && (c = getchar()) != '\n' && c != EOF; ++i){
        line[i] = c;
    }

    if(c == '\n'){
        line[i] = '\n';
        ++i;
    }

    line[i] = '\0';
    return i;
}

//If the char array contains numbers, it converts them to an int.
int atoi(char s[]){
    int i, n;

    n = 0;
    for(i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
        n = 10 * n + (s[i] - '0');
    return n;
}