#include "stdio.h"
#include "string.h"
#define MAX_STR_SIZE 256

int main(){
	char str[MAX_STR_SIZE];
	
	printf("Input a random string for reversing: ");
	fgets(str, MAX_STR_SIZE, stdin);
	for(int i = 0; i < strlen(str) / 2; i++){
		char temp = str[i];
		str[i] = str[strlen(str) - i - 1];
		str[strlen(str) - i - 1] = temp;
	}
	printf("\nReversed string: %s", str);
	return 0;
}
