#include <stdio.h>

/* Counts digits, white space, and other characters */

int main() {
    int c, i, nwhite, nother;
    int ndigit[10]; // Array to store the count of each digit (0-9)

    nwhite = nother = 0; // Initialize counters for white space and other characters
    for (i = 0; i < 10; ++i)
        ndigit[i] = 0; // Initialize digit count array to all zeros

    // Read characters from input until end of file (EOF) is reached
    while ((c = getchar()) != EOF)
        if (c >= '0' && c <= '9')
            ++ndigit[c - '0']; // The expression c - '0' converts the character c to its corresponding integer value.
        else if (c == ' ' || c == '\n' || c == '\t')
            ++nwhite;
        else
            ++nother;

    // Print the results
    printf("Digits =");
    for (i = 0; i < 10; ++i)
        printf(" %3d", ndigit[i]);
    printf(",\tWhite Space = %3d,\tOther = %d\n", nwhite, nother);

    return 0;
}
