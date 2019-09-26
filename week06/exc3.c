#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void notify(int s) {
   printf("Caught signal SIGINT: %d. My work is done.\n", s);
   exit(1);
}

int main () {
   signal(SIGINT, notify);

   while(1) {
      printf("Waiting for signal...\n");
      sleep(2); 
   }
   return 0;
}

/* 

-- Output --

Waiting for signal...
Waiting for signal...
^CCaught signal SIGINT: 2. My work is done.

*/