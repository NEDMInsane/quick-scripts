#include<stdio.h>

//counts the lines (new line chars)

int main(){
	int c, n1;

	n1 = 0;
	while ((c = getchar()) != EOF)
	/*"'\n'" represents the new line character which is an integer
	 * ""\n"" represents the new line character which is a string */
		if (c == '\n')
			++n1;
	printf("%d\n", n1);

	return 0;
}
