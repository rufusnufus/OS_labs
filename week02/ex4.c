#include "stdio.h"
#define MAX_STR_SIZE 256

void swap_numbers(int*, int*);

int main(){
	char str[MAX_STR_SIZE];
	int num_1, num_2;
	printf("Input 2 random numbers to swap, separate by space: ");
	fgets(str, MAX_STR_SIZE, stdin);
	sscanf(str, "%d%d", &num_1, &num_2);
	swap_numbers(&num_1, &num_2);
	printf("\nSwapped numbers: %d %d", num_1, num_2);
	return 0;
}

void swap_numbers(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
