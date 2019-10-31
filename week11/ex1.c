#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	char * str = "This is a nice day";

	int fd = open("ex1.txt", O_RDWR);

	//handle problems with opening file
	if (fd < 0){
		printf("Error");
		exit(1);
	}

	struct stat buff;
	fstat(fd, &buff);

	//mapping
	char * address = mmap(NULL, buff.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	//coping the string into file
	strcpy(address, str);
	//resizing file
	ftruncate(fd, strlen(str));
	close(fd);

	return 0;
}