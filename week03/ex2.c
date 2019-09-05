#include <stdio.h>
#include <stdlib.h>

int compareInt(int * a, int * b){
	return *a - *b;
}

void bubble_sort(int* arr, int size, int compare(int *, int *)){
	for(int i = 0; i < size; ++i){
		for (int j = 0; j < size - i - 1; ++j)
		{
			if(compare(&arr[j], &arr[j + 1]) > 0){
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main(){
	printf("Enter the number of elements in array: ");

	int num;
	scanf("%d", &num);

	int* a = (int*) malloc(num * sizeof(int));

	printf("\nWrite %d integer number(s): ", num);
	for (int i = 0; i < num; ++i)
	{
		scanf("%d", &a[i]);
	}

	bubble_sort(a, num, compareInt);
	
	printf("\nSorted sequence of numbers: ");
	for (int i = 0; i < num; ++i)
	{
		printf("%d ", a[i]);
	}
	return 0;
}