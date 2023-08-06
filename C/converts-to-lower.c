#include<stdio.h>

/* The program will take the inoput char and conver it to lower if it
    is an uppercase character. <ctype.h> has a tolower() function that
    we can use.*/

int lower(int c);

int main(){
    int c;

    while((c = getchar())!= EOF){
        //Use putchar() becuase if you printf it will output the number 
        putchar(lower(c));
    }
}

/* int lower(int c){
    if(c >= 'A' && c <= 'Z'){
        return c + 'a' - 'A';
    } else {
        return c;
    }
} */

/*exercise 2-10 below */
int lower(int c){
    // Uses conditional expressions - expr-1 ? expr-2 : expr-3;
    // if expr-1 is true expr-2 is executed, if its false expr-3 is executed.
    c >= 'A' && c <= 'Z' ? c = c + 'a' - 'A' : c;

    return c;
}

/**/