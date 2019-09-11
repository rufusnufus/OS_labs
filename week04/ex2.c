/* Before the loop there is only one process(main process).
 * After first iteration of loop we can see two processes,
 * because we made a new one by fork() command.
 * After second iteration a new one was made during each 
 * of processes. So, by second iteration of loop we have 
 * 4 processes already. By third, 8 processes.  On each
 * iteration of the loop each process make new one("like doubles").
 * The number of processes is 2^(n), where n - the number of
 * iterations of the loop. To run this program, run ex2.sh.
 */ 
#include <stdio.h>
#include <unistd.h>

int main() {
	sleep(1);
	for (int i = 0; i < 3; ++i)
	{
		fork();
		sleep(5);
	}
	return 0;
}