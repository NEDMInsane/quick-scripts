#include <stdio.h>


/*
If you want to swap the variables in just the function but leave the how they are
in the main(or whatever other func) you could use this function.
void swap(int a, int b) {
	int t = a;
	a = b;
	b = t;
	printf("Swap: a = %d, b = %d\n", a, b);
}
*/

//instead you could use pointers to swap the values.
//use the * (indirection) operator to declare pointers and dereference them
void swap(int *pa, int *pb){
	int t = *pa;
	//if there was no * it would change the data of the pointer
	//the * at the beginning dereferences the pointer to the actual var
	*pa = *pb;
	*pb = t;
	return;
}


int main(void) {
	//declaring two integers, and assigning value
	//these variables have a lifetime, when leaving this block they 
	//will be discarded. Automatic Storage Duration
	int a = 21;
	int b =17;
	
	//calling our 'swap' function
	//the ambersand is is the address-of operator.
	swap(&a, &b);

	//printing the results %d is the formatting for an int (digit)
	printf("Main: a = %d, b = %d\n", a, b);
	
	//return 0 to exit the program, with no error (use a number for an error)
	return 0
}
