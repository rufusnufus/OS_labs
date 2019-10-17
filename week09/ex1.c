#include <stdio.h>
#include <stdlib.h>

//Shifts every element(except elements that equal to -1) of array arr
void shift_right_1bit(int * arr,  int array_size){
	for (int i = 0; i < array_size; ++i)
	{
		if(arr[i] != -1){
			arr[i] >>= 1;
			arr[i] &= (unsigned int)0b01111111111111111111111111111111;
		}
		
	}
}

/*
 * Finds oldest page, that means according to aging algorithm
 * to find the element with the smallest value.
 * Return the index of this element
 */
int oldest_page(int * arr,  int array_size){
	int old_page = 0;
	for (int i = 1; i < array_size; ++i)
	{
		if(arr[i] < arr[old_page]){
			old_page = i;
		}
	}
	return old_page;
}

//function responsible for aging algorithm
//returns 1 if hits page
//returns 0 if misses page
int aging_algo(int page, int * pages, int * stats, int arrays_size){
	int return_val;

	//shifts each element of stats to right by one bit
	shift_right_1bit(stats, arrays_size);

	int pos = 0;
	for (int i = 0; i < arrays_size; ++i)
	{
		//if finds page in virtual memory,
		//return value automatically equals 1 - hit,
		//remembers the position of the page in virtual memory 
		//with idea of adding Rbit.
		//goes to addRbit function
		if(pages[i] == page){
			return_val = 1;
			pos = i;
			goto add_Rbit;
		}
	}
	//if doesn't find this page in virtual memory
	//return value automatically equals 0 - miss 
	return_val = 0;
	//find the position of the oldest page
	pos = oldest_page(stats, arrays_size);
	//replace the oldest page with the page
	stats[pos] = 0;
	pages[pos] = page;
	//adding Rbit to stats of page
	add_Rbit: stats[pos] |= (unsigned int)0b10000000000000000000000000000000;
	//return hit(1)/miss(0)
	return return_val;
}

int main(){
	int page_frames;
	printf("%s", "Number of page frames: ");
	scanf("%d", &page_frames);

	//array for holding pages in virtual memory 
	int * pages_in_virtual;
	pages_in_virtual = (int *) malloc(page_frames * sizeof(int));

	//array for holding status of pages in virtual memory
	int * pages_status;
	pages_status = (int *)malloc(page_frames * sizeof(int));

	//initializing arrays
	for (int i = 0; i < page_frames; ++i)
	{
		pages_in_virtual[i] = -1;
		pages_status[i] = -1;
	}

	FILE * in = fopen("Lab 09 input.txt", "r");

	int hit = 0, miss = 0;
	int cur_page;
	while (fscanf(in, "%d", &(cur_page)) != EOF) {
		int val = aging_algo(cur_page, pages_in_virtual, pages_status, page_frames);
		//adding val, we will sum 1, if it was hit, 0 will not affect on our sum of hits
		hit += val; 
		//adding val, we will sum 1, if it was miss, because xor 0 with 1 will be 1
		//if it was hit, then xor of 1 and 1 will be 0, and no affect on our sum of misses
		miss += val^1; 
	}

	fclose(in);

	printf("Hit/Miss Ratio: %f\n", (float)hit / miss);

	free(pages_in_virtual);
	free(pages_status);

	return 0;
}

/*
	
 --Output--
 Number of page frames: 10
 Hit/Miss Ratio: 0.010101

 Number of page frames: 50
 Hit/Miss Ratio: 0.054852

 Number of page frames: 100
 Hit/Miss Ratio: 0.108647

 */
