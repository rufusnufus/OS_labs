/* We ran the program 10 times using ex1.sh.
 * After running the program we got different PIDs of parent
 * and child, but the same value of n per each call of the program.
 * Different PIDs are because each process has unique id
 * Same n is because child and parent processes initially have 
 * the same arguments and their states. Of course, when we rerun 
 * the program, the value of n differs from previous execution, 
 * but it is again the same in child and parent process.
 */

#include <stdio.h>
#include <unistd.h>

int main() {
	int n;
	if(fork()){
		printf("Hello from parent [%d - %d]\n", getpid(), n);
	}else{
		printf("Hello from child [%d - %d]\n", getpid(), n);
	}
	return 0;
}