#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(){
	char * str = "Hello";

	setvbuf(stdout, NULL, _IOLBF, strlen(str));

	for (int i = 0; i < strlen(str); ++i)
	{
		printf("%c", str[i]);
		sleep(1);
	}
	return 0;
}