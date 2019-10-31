#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	int fd1 = open("ex1.txt", O_RDWR);
	int fd2 = open("ex1.memcpy.txt", O_RDWR | O_CREAT, 0666);

	//handle problems with opening files
	if (fd1 < 0){
		printf("Error in opening ex1.txt");
		exit(1);
	}else if (fd2 < 0){
		printf("Error in opening ex1.memcpy.txt");
		exit(1);
	}

	struct stat buff;
	fstat(fd1, &buff);

	//resizing the second file for mapping
	ftruncate(fd2, buff.st_size);

	//mapping
	char * address1 = mmap(NULL, buff.st_size, PROT_READ, MAP_SHARED, fd1, 0);
	char * address2 = mmap(NULL, buff.st_size, PROT_WRITE, MAP_SHARED, fd2, 0);

	//coping the content
	memcpy(address2, address1, buff.st_size);
	
	//close files
	close(fd1);
	close(fd2);

	return 0;
}