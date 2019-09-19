/*
 * Here's a problem of producer and consumer.
 * The program met a fatal race condition after 1 second.
 * The minimum of cookies is 0.
 * The maximum of cookies is 20.
 */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MIN 0
#define MAX 20

int sleep_cons = 1, sleep_prod = 0, counter = 0;

void *consume(void *a){
	while(1){
		while(sleep_cons);
		counter--;
		if(counter <= MIN){
			sleep_cons = 1;
			sleep_prod = 0;
		}
	}
}

void *produce(void *a){
	while(1){
		while(sleep_prod);
		counter++;
		if(counter >= MAX){
			sleep_cons = 0;
			sleep_prod = 1;
		}
	}
}

int main(){
	pthread_t prod, cons;
	pthread_create(&prod, NULL, produce, NULL);
	pthread_create(&cons, NULL, consume, NULL);
	while(1){
		printf("Cooookies: %d\n", counter);
		printf("Producer sleeps: %d, consumer sleeps: %d\n", sleep_prod, sleep_cons);
		sleep(1);
	}
	pthread_join(cons, NULL);
    pthread_join(prod, NULL);
	return 0;
}