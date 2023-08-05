#include<stdio.h>

/* This program copys the input to the output but will actually print
 * tabs, back spaces, and backslashes.
 * 	This is exercise 1-10 of The C programming Language */

int main(){
	int c;

	while((c = getchar()) != EOF){
		if(c == '\t'){
			putchar('\\');
			putchar('t');
		} else if (c == '\b'){
			putchar('\\');
			putchar('b');
		} else if (c == '\\'){
			putchar('\\');
			putchar('\\');
		} else {
			putchar(c);
		}
	}
	return 0;
}
