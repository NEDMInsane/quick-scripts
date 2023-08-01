#include<stdio.h>

static unsigned int counter = 0;

void increment(void){
	//static unsigned int counter = 0; //static here is decalring the object is in static duration
	counter++;
	//printf("%d ", counter);
}

int retreive(void) {
	return counter;
}

int main(void){
	for(int i = 0; i < 5; i++){
		increment();
		printf("%d", retreive());
	}
	return 0;
}
