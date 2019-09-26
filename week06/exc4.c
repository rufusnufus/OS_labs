#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>


void notify(int s){
	if(s == SIGINT){
		printf("Caught signal SIGINT: %d. My work is done.\n", s);
	}else if(s == SIGKILL){
		printf("Caught signal SIGKILL: %d. My work is done.\n", s);
	}else if(s == SIGSTOP){
		printf("Caught signal SIGSTOP: %d. My work is done.\n", s);
	}else if(s == SIGUSR1){
		printf("Caught signal SIGUSR1: %d. My work is done.\n", s);
	}
	exit(1);
}

int main(){
	signal(SIGINT, notify);
	signal(SIGKILL, notify);
	signal(SIGSTOP, notify);
	signal(SIGUSR1, notify);

	while(1) {
      printf("Waiting for signal...\n");
      sleep(4); 
   }
	return 0;
}

/* 
The signal with kill command sent
The program understood it
Showed corresponding output
And exit

-- Output --

Waiting for signal...
Waiting for signal...
kill -SIGUSR1 2002
Caught signal SIGUSR1: 30. My work is done.
[1]+  Exit 1                  ./ex4.o

*/