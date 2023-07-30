#include<stdio.h>

/*This program will copy the input to the output,
 * as long as EOF isnt passed */

int main(){
	int c;

	while((c = getchar()) != EOF){
		printf("'c' is not EOF: ");
		putchar(c);
	}
	if (c == EOF){
		printf("'c' is EOF: ");
		putchar(c);
	}
	putchar(c);
	return 0;
}
