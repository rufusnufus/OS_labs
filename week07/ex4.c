/*
 * new_realloc is realised.
 * For checking the function I copied the main code from exercize 3 and 
 * substitute new_realloc function instead of realloc. Output remains the same.
 */

#include <stdio.h>
#include <stdlib.h>

void * new_realloc(void * ptr, int new_size){
	//new pointer that we wil return as a result
	void * new_ptr;
	//size of current array
	unsigned int size;

	if(ptr == NULL){
		new_ptr = malloc(new_size);
	}else if(new_size <= 0){
		new_ptr = NULL;
	}else{
		//calculating the size of array given as argument
		unsigned int size = *(&ptr + 1) - ptr;

		if(new_size <= size){
			new_ptr = ptr;
		}else{
			new_ptr = malloc(new_size);
			//coping first elements
			for (int i = 0; i < size; ++i)
			{
				*(char *)(new_ptr + i) = *(char *)(ptr + i);
			}
		}
	}
	//deallocate memory
	free(ptr);
	//return pointer to reallocated memory
	return(new_ptr);
}

int main(){
	srand(time(NULL));
	printf("Enter original array size:");
	int n1=0;
	scanf("%d",&n1);
	int* a1 = (int*) calloc(n1, sizeof(int));
	int i;
	for(i=0; i<n1; i++){
		*(a1+i)=100;
		printf("%d ", *(a1+i));
	}
	printf("\nEnter new array size: ");
	int n2=0;
	scanf("%d",&n2);
	a1 = new_realloc(a1,n2);
	if(n2>n1){
		for (int i = n1+1; i < n2; ++i)
		{
			*(a1+i) = 0;
		}
	}
	for(i=0; i<n2;i++){
		printf("%d ",*(a1+i));
	}
	printf("\n");
	return 0;
}

