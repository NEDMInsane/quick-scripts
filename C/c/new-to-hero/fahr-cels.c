#include<stdio.h>

/* This program will output Fahrenheit temouratures
 * with the equivalent Celsius value, in 20 degree increments */

int main(){
	int fahr, cels;
	int upper, lower, step;

	upper = 300;
	lower = 0;
	step = 20;
	
	/* you can also use a while loop:
	 * fahr = lower
	 * while(fahr <= upper){
	 * 	//pretty much the same except for this next line:
	 * 	fahr = fahr + step;
	 * 	}
	 *							*/
	
	for(fahr = lower; fahr <= upper; fahr = fahr + step){
		cels = 5 * (fahr-32) / 9;
		printf("%3d %6d\n", fahr, cels); //'\t' adds a tab '3' and '6' define width
	}
	return 0;
}


