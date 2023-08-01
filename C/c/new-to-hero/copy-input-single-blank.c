#include<stdio.h>

/* This program takes the input and copies it to the output,
 * but it takes any multipule blanks spaces and reduces it to 1 space
 * 	This is exercise 1-9 in The C Programming Language. */

int main(){
	int c, prev_c;

	while((c = getchar()) != EOF){
		if(c != ' ' || c == ' ' && prev_c != ' '){
			putchar(c);
			prev_c = c;
		}
	}
	return 0;
}
