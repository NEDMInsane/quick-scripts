#include<stdio.h>

/*counts charaters in input*/

int main(){
	double nc;

	nc = 0;
	/*When one statement follows the while statement (
	 * 	in this case "++nc;")
	 * you do not need to use curly brackets. */
	while (getchar() != EOF)
		++nc;
	printf("%.0f\n", nc);
}

/* This prgram could also be written as:
 * 	double nc;
 *
 * 	for (nc = 0; getchar() != EOF; ++nc)
 * 		;
 * 	printf("%.0f\n", nc);
 *
 * The for loop(and while loops) need a body, so the blank
 * 	line is needed (AKA a null statment). 
 * 	All of the operations we need happen in the loop statement. */
