#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define STR_LEN 256

int main() {
	char *s = (char*) malloc(STR_LEN * sizeof(char));
	int work = 1;
	printf("Welcome to simplistic shell. You can close it by pressing q.\n");
	do{
		scanf("%s", s);
		if(*s == 'q'){
			work = 0;
		}else{
			system(s);
		}

	}while(work);	
	return 0;
}