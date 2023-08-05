#include<stdio.h>

#define MAXLINE 5000

/* This program takes in a string of characters, reverses them, and spits it back out
    This is exercise 1-19 in The C Programming Language. */

// Function prototypes
int getLine(char line[], int maxline);
void reverse(char line[], char r_line[], int len);

int main(){
    char line[MAXLINE], r_line[MAXLINE];
    int len, i;

    // Read lines from input until end of file (EOF) is encountered
    while((len = getLine(line, MAXLINE)) > 0){
        // Reverse the line and store the reversed version in 'r_line'
        reverse(line, r_line, len);
        // Print the reversed line
        printf("%s", r_line);
    }
    return 0;

}

// Function to reverse the input line
void reverse(char line[], char r_line[], int len){
        int i;

        // Loop through the characters of the input line in reverse order
        for(i = 0; i < len - 1; ++i){
            // Place each character from the input line in reverse order into 'r_line'
            r_line[len - 2 - i] = line[i];
            // printf("%d\n", len - i);
        }
        r_line[i++] = '\n'; // Add a newline character to the end of the reversed line
        r_line[i] = '\0';   // Add a null terminator to mark the end of the reversed line
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
