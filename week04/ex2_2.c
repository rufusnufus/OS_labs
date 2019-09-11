/* As we saw in the previous program:
 * The number of processes is 2^(n), where n - the number of
 * iterations of the loop. There are 32 processes here.
 * To run this program, run ex2_2.sh.
 */ 
#include <stdio.h>
#include <unistd.h>

int main() {
	sleep(1);
	for (int i = 0; i < 5; ++i)
	{
		fork();
		sleep(5);
	}
	return 0;
}