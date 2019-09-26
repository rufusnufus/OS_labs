#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int main () {
	int pid = fork();
	if(pid == 0){ //child
		//shows that it is working
		while(1){
			printf("I'm alive\n");
			sleep(1);
		}
	}
	else{ //parent
		sleep(10);
		printf("SIGTERM is sent to a child, really sorry:(\n");
		kill(pid, SIGTERM);//sends SIGTERM to child
	}
	return 0;
}

/*
-- Output --

I'm alive
I'm alive
I'm alive
I'm alive
I'm alive
I'm alive
I'm alive
I'm alive
I'm alive
I'm alive
SIGTERM is sent to a child, really sorry:(

*/