int j; //file scope (can be accesed anywhere in this file

void f(int i) {				//block scope of 'i' begins
	int j = 1;			//block scope of 'j' begins (this hides the files scope 'j')
	i++;				//refers to the function parameter
	
	for(int i = 0; i < 2; i++){	//block scope of loop-local 'i' begins
		int j = 2;		//block scope of inner 'j' begins; hides outer 'j'
		printf("%d\n", j);	//inner 'j' is in scope, pintd '2'
	}				//block scope of inner 'i' and 'j' ends
	printf("%d\n", j);		//the outer 'j' is in scope, prints '1'
}					//block scope of 'i' and 'j' ends

void g(int j)				//'j' function prototpe scope; hides file-scope 'j'

