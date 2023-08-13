#include<stdio.h>

int strrindex(char[], char);

int main(){
    char wordlist[] = "words are just words dude";
    char searchterm;
    int index;

    printf("Enter seach char: ");
    searchterm = getchar();
    index = strrindex(wordlist, searchterm);

    if(index >= 0)
        printf("Found at index: %d\n", index);
    else
        printf("Term not found!!!\n");

    return 0;
}

int strrindex(char list[], char sterm){
    int i;

    for(i = 0; i < sizeof(&list); ++i)
        if(list[i] == sterm)
            return i;

    return -1;
}