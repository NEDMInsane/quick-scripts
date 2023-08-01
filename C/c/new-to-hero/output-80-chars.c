#include <stdio.h>

#define MAXLINE 1000
#define MINLINE 80

// Function prototypes
int getLine(char line[], int maxline);

int main() {
    int len; // Length of the current line
    char line[MAXLINE];    // Current input line


    // Read lines from input until end of file (EOF) is encountered
    while ((len = getLine(line, MAXLINE)) > 0) {
        if (len >= MINLINE) {
            printf("%s", line);
        }
    }
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
