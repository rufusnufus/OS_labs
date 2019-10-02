#include <stdio.h>
#include <stdlib.h>

int main(){
	int n;
	printf("Input any positive number: ");
	scanf("%d", &n);
	//allocate exact amount of memory for n integers user wants
	int * array = (int *) calloc(n, sizeof(int));

	printf("Array is created. It's content: ");
	//filling the array with incremental values starting from 0
	for (int i = 0; i < n; ++i){
		*(array + i) = i;
		printf("%d ", *(array + i));
	}
	printf("\n");
	//deallocating memory
	free(array);
	return 0;
}

/*

--Output--
Input any positive number: 5
Array is created. It's content: 0 1 2 3 4

*/