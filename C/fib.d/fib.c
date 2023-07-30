#include<stdio.h> //Include the standard IO library

int main(){
    //declare Integers
    int n1 = 0, n2 = 1, n3, i, number;

    printf("Enter the number of elements of Fibonacci you want:\n");
    scanf("%d", &number);
    //print 0 and 1
    printf("%d %d", n1, n2);

    //start this loops at 2 because 0 and 1 are already printed
    for(i=2; i < number; ++i){
        n3 = n1 + n2;
        printf(" %d", n3);
        n1 = n2;
        n2 = n3;
    }
    printf("\n");
    return 0;
}
