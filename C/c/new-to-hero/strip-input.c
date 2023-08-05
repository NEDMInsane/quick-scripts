#include<stdio.h>

#define MAXLINE 5000

/*This program removes trailing blanks, tabs and new lines from an input line
    This is exercise 1-18 in The C Programming Language*/

void strip(char line[], int len);
int getLine(char line[], int maxline);

int main(){
    char line[MAXLINE];
    int len;

    while((len = getLine(line, MAXLINE)) > 0){
        strip(line, len);
        printf("%s\n", line);
    }


    return 0;
}

void strip(char line[], int len){
    int i;
    int word = 0;

    while(word == 0){
        //printf("%d", len);
        for(i = len - 1; i >= 0; --i){
            //printf("%d", i);
            if(line[i] == ' ' || line[i] == '\n' || line[i] == '\t'){
                line[i] = '\0';
            }else{
                word = 1;
                break;
            }
        }
    }
    line[i] = '\0';
}

// Function to read a line from input and store it in 's'
// Returns the length of the line (excluding the null terminator)
int getLine(char s[], int lim){
    int c, i;

    // Read characters until the line length reaches 'lim-1' or a newline is encountered
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    // If a newline is encountered, add it to the line and increment the length
    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0'; // Add the null terminator to mark the end of the string
    return i;    // Return the length of the line (excluding the null terminator)
}