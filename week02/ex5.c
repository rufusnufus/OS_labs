#include "stdio.h"
#define MAX_STR_SIZE 256

void print_triangle(int);
void print_isosceles(int);
void print_sideways(int);
void print_column(int);

int main(){
	char str[MAX_STR_SIZE], mode;
	int num;
	printf("There are 4 options of figures: T-side-up, R-right isosceles, S-sideways triangles, C - column.\n");
	printf("Input the letter of figure you want to see: ");
	scanf("%c", &mode);
	printf("Input a random number: ");
	fgets(str, MAX_STR_SIZE, stdin);
	sscanf(str, "%d", &num);
	if (mode == 'T' || mode == 't') print_triangle(num);
	else if (mode == 'R' || mode == 'r') print_isosceles(num);
	else if (mode == 'S' || mode == 's') print_sideways(num);
	else if (mode == 'C' || mode == 'c') print_column(num);
	else printf("No such figure in the programme:(\n");
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

void print_isosceles(int n){
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			printf("*");
		}
		printf("\n");
	}
}

void print_sideways(int n){
	print_isosceles(n);
	for (int i = n-1; i > 0; i--)
	{
		for (int j = i; j > 0; j--)
		{
			printf("*");
		}
		printf("\n");
	}
}
void print_column(int n){
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			printf("*");
		}
		printf("\n");
	}
}