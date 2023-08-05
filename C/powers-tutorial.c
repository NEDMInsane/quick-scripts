#include<stdio.h>

/* This is a function prototype
 *  Its stating that power will take 2 arguments
 *  These argument NAMES dont have to match the function declaration*/
int power(int m, int n);

int main(){
    int i;

    for(i = 0; i < 10; ++i)
        printf("%d\t%d\t%d\n", i, power(2, i), power(-3, i));
    return 0;
}

int power(int base, int n){
    int i, p;

    p = 1;
    for(i = 1; i <= n; ++i)
        p = p * base;
    return p;
}