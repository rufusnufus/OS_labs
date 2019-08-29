#include "stdio.h"
#define MAX_STR_SIZE 256

void print_triangle(int);

int main(){
	char str[MAX_STR_SIZE];
	int num;

	printf("Input a random number: ");
	fgets(str, MAX_STR_SIZE, stdin);
	sscanf(str, "%d", &num);
	print_triangle(num);
	return 0;
}

void print_triangle(int n){
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < (2 * n - (2 * i - 1)) / 2; j++){
			printf(" ");
		}
		for(int j = 0; j < 2 * i - 1; j++){
			printf("*");
		}
		for(int j = 0; j < (2 * n - (2 * i - 1)) / 2; j++){
			printf(" ");
		}
		printf("\n");
	}
}