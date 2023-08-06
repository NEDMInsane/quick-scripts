#include<stdio.h>

/* This is a program that uses the Algorithm called 'Binary Search'
    the way it works is it take in a search term, a sorted list, and the length
    of the sorted list. It then cuts that in half and return the result if its
    what we are looking for. If not we keep halfing it till we find the right
    term we are looking for. This version uses 1 test in the loop, exercise 3-1 in
    The C Programming Language.*/

int binsearch(int, int[], int);

int main(){
    int x[101];
    int i, term, index;
    char c;

    //Lets create an ordered list 0 to 100.
    for(i = 0; i < 100; ++i){
        x[i] = i;
    }

    printf("Enter the number you want to search for: ");
    scanf("%d", &term);

    if((index = binsearch(term, x, i)) >= 0)
        printf("Found at %d.\n", index);
    else
        printf("Did not find %d in list.\n", term);

    return 0;
}

int binsearch(int sterm, int list[], int len){
    int low, mid, high;

    low = 0;
    high = len - 1;
    mid = (low + high) / 2;
    
    while(low <= high && list[mid] != sterm){
        mid = (low + high) / 2;
        if(sterm < list[mid])
            high = mid -1;
        else
            low = mid + 1;
    }
    if(list[mid] == sterm)
        return mid;
    else
        return -1;
}