#include<stdio.h>

/* This program counts what is input, buth this one uses Switch Case*/

int main(){
    int c, i, nwhite, nother, ndigits[10];

    nwhite = nother = 0;
    for(i =0; i < 10; i++){
        ndigits[i] = 0; //Initialize the array
    }
    while((c = getchar()) != EOF){
        switch(c){
            case '0': case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9':
                ndigits[c - '0']++;
                break;
            case ' ':
            case '\n':
            case '\t':
                nwhite++;
                break;
            default:
                nother++;
                break;
        }
    }

    printf("Digits - ");
    for(i = 0; i < 10; i++)
        printf("%d ", ndigits[i]);
    printf("\tWhite Space - %d \tOther - %d \n", nwhite, nother);
    
    return 0;
}