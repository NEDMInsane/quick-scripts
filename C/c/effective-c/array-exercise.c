#include<stdio.h>

void f0(void){
	printf("f0 invoked\n");
}

void f1(void){
	printf("f1 invoked\n");
}

void f2(void){
	printf("f2 invoked\n");
}

int main(void){
        //return_type (*array_name[size])(parameters)
	void (*funcArray[3])() = { f0,f1,f2 };
	//'*' is used to the array is an array of pointers

	int index;
	printf("Enter an index value (0, 1 =, or 2): ");
	scanf("%d", &index);

	if (index >= 0 && index < 3){
		funcArray[index]();
	} else {
		printf("Invalid Index.");
	}

	return 0;
}
