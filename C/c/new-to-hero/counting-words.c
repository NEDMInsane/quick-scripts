#include<stdio.h>

/* Counts all the words, lines and characters. */

#define IN 1
#define OUT 0

int main(){
	int c, nl, nw, nc, state;

	state = OUT;
	nl = nw = nc = 0;

	while ((c = getchar()) != EOF){
		++nc;
		if (c == '\n')
			++nl;
		if (c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if (state == OUT){
			state = IN;
			++nw;
		}
	}
	printf("New Lines: %3d\tWords: %3d\tCharacters: %3d\n", nl, nw, nc);
}
