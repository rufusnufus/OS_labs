#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#define STR_LEN 256

int main() {
	char *s = (char*) malloc(STR_LEN * sizeof(char));
	int work = 1;
	printf("Welcome to simplistic shell. You can close it by pressing q.\n");
	do{
		fgets(s, STR_LEN, stdin);
		if(*s == 'q'){
			work = 0;
		}else if(*s == '\n'){
			system(s);
		}else{
			s[strlen(s)-1] = '&';
			s[strlen(s)] = '\0';
			system(s);
		}

	}while(work);	
	return 0;
}