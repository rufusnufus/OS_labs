#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BYTES 1024
#define MB_NUMBER 10
#define SEC_PROG_RUNS 10

int main(){
	for (int i = 0; i < SEC_PROG_RUNS; ++i)
	{
		//allocating memory for 10MB(10*1024*1024 bytes)
		void * ptr = malloc(MB_NUMBER * BYTES * BYTES);
		//filling memory with zeros 
		memset(ptr, 0, MB_NUMBER * BYTES * BYTES);
		sleep(1);
	}
	return 0;
}

/*
 Command in the shell: ./ex2& vm_stat -c 10 1

 -- Output --

 [1] 13300
 Mach Virtual Memory Statistics: (page size of 4096 bytes)
  free   active   specul inactive throttle    wired  prgable   faults     copy    0fill reactive   purged file-backed anonymous cmprssed cmprssor  dcomprs   comprs  pageins  pageout  swapins swapouts
 22216   530560     2168   527819        0   456293    12287  505014K 15275993  302657K 56375267 14147170      256699    803848  2192454   557569 58696682 78994373 11253690   180018  3006161  3459371 
 16870   532109     2348   529308        0   458350    14221     5266       12     6793        0        0      256879    806886  2192403   557569       51        0        7        0        0        0 
 14700   532261     2358   529305        0   460334    12256     2930        6     2747        0        0      256889    807035  2192396   557569        7        0        0        0        0        0 
 12277   538260     2392   531625        0   454307    13033     2736        6     2640        0        0      256923    815354  2192381   557569       15        0        0        0        0        0 
  9230   541202     2393   534329        0   451904    15225     3423        7     2595        0        0      256924    821000  2191699   557473      682        0        0        0        0        0 
  7979   551512     2393   535286        0   441824    15239     2682        5     2583        0        0      256924    832267  2191671   557473       28        0        0        0        0        0 
  5582   556628     2427   536037        0   438451    15280     2720        6     2635        0        0      256958    838134  2191670   557473        1        0        0        0        0        0 
  3607   553285     1401   542978        0   437625    15934     2974        5     2923        0        2      255990    841674  2191667   557473        3        0        0       60        0        0 
  4136   549153       76   548229        0   437501    15934     2633        4     2598      448        0      254485    842973  2191772   557497        1      106        0       81        0        0 
  5234   549304       96   548278        0   437398    15934     2780        5     2706      754        0      254505    843173  2192377   556331        0      605       17        0        0       64 

 */