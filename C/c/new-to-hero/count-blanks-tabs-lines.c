#include<stdio.h>

/* This program counts the blanks tabs and newlines
 * then outputs it to the stdout. 
 * This is exercise 1-8 in 'The C Programming Language"*/

int main(){
	int blanks, tabs, lines = 0;
	int c;

	while ((c = getchar()) != EOF){
		if (c == '\n'){
			++lines;
		}else if (c == '\t'){
			++tabs;
		}else if (c == ' '){
			++blanks;
		}}

	printf("Blanks: %d\tTabs: %d\tLines: %d\n", blanks, tabs, lines);
	
	return 0;
}
