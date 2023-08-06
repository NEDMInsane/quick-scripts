#include <stdio.h>
#include <string.h>

/* This function looks for chars in a that appear in b and removes them 
    if they are common, if not it keeps them this is exercise 2-4 this can 
    also be used to complete exercise 2-5 in The C Programming Langauge.*/

void strsqueeze(char[], char[]);

int main(){
    char a[] = "dogtor";
    char b[] = "dog";

    strsqueeze(a, b); // Call the strsqueeze function to modify string a
    printf("Output: %s\n", a); // Print the modified string a
    return 0;
}

// Function to remove characters in string a that appear in string b
void strsqueeze(char a[], char b[]){
    int i, j, found;
    char c[500]; // Create a new array to store the modified string
    int mod = 0; // Initialize a modifier for the new array

    // Loop through each character in string a
    for(i = 0; a[i] != '\0'; ++i){
        found = 0; // Initialize the found flag to 0 for each character in a

        // Loop through each character in string b to check for a match
        for(j = 0; b[j] != '\0'; ++j){
            if(a[i] == b[j]){
                found = 1; // Set found flag to 1 if a common character is found
                break;     // No need to check further, exit the loop
            }
        }

        // If character in a is not found in b, copy it to the new array c
        if(found != 1){
            c[mod] = a[i]; // Copy character from a to c
            ++mod;         // Increment modifier for the new array
        }
    }

    c[mod] = '\0';   // Add null terminator to the end of the new string c
    strcpy(a, c);    // Copy the content of c back to original string a
}