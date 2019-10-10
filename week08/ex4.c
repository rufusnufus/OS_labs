#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

#define BYTES 1024
#define MB_NUMBER 10
#define SEC_PROG_RUNS 10

int main(){
	struct rusage usage;
	for (int i = 0; i < SEC_PROG_RUNS; ++i)
	{
		//allocating memory for 10MB(10*1024*1024 bytes)
		void * ptr = malloc(MB_NUMBER * BYTES * BYTES);
		//filling memory with zeros 
		memset(ptr, 0, MB_NUMBER * BYTES * BYTES);
		getrusage(RUSAGE_SELF, &usage);
		printf("Memory usage = %ld\n",usage.ru_maxrss);
		sleep(1);
	}
	return 0;
}

/*

 -- Output --

 Memory usage = 11280384
 Memory usage = 21778432
 Memory usage = 32264192
 Memory usage = 42749952
 Memory usage = 53235712
 Memory usage = 63721472
 Memory usage = 74207232
 Memory usage = 84692992
 Memory usage = 95178752
 Memory usage = 105664512

 */