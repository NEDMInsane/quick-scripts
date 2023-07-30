#include<stdio.h>

/*does the same thing as fahr-cels but uses
 * floating point number operations for more accuracy. */

/*"LOWER", "UPPER", and "STEP" are not variables thet are symbolic constants
 * 	symbolic constants - #define NAME REPLACEMENT_TEXT
 * 	anytime NAME is in the program the compiler sees REPLACEMENT_TEXT */

#define LOWER 0
#define UPPER 300
#define STEP 20

int main(){
	float fahr, cels;

	fahr = LOWER;
	while(fahr <= UPPER){
		//we can do "5.0/9.0" becuase its not integer math.
		cels = (5.0/9.0) * (fahr-32.0);
		/*'3.0' defines 3 numbers wide, 
		*'6.1' defines 6 numbers wide 1 being adter decimal */
		printf("%3.0f %6.1f\n", fahr, cels);
		fahr = fahr + STEP;
	}
	return 0;
}
