#include <stdio.h>

#define MAXLINE 1000

// Function prototypes
int getLine(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
    int len; // Length of the current line
    int max; // Length of the longest line seen so far
    char line[MAXLINE];    // Current input line
    char longest[MAXLINE]; // Longest line saved here

    max = 0; // Initialize the maximum length to zero

    // Read lines from input until end of file (EOF) is encountered
    while ((len = getLine(line, MAXLINE)) > 0) {
        // Check if the current line is longer than the longest line seen so far
        if (len > max) {
            max = len; // Update the maximum length
            copy(longest, line); // Copy the current line to 'longest'
        }
    }

    // If there was at least one non-empty line, print the longest line
    if (max > 0)
        printf("%s", longest);

    return 0;
}

// Function to read a line from input and store it in 's'
// Returns the length of the line (excluding the null terminator)
int getLine(char s[], int lim) {
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

// Function to copy the contents of 'from' to 'to'
void copy(char to[], char from[]) {
    int i = 0;

    // Copy characters from 'from' to 'to' until the null terminator is encountered
    while ((to[i] = from[i]) != '\0')
        ++i;
}
