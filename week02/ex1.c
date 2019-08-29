#include "stdio.h"
#include "limits.h"
#include "float.h"

int main(){
	int max_int = INT_MAX;
	float max_float = FLT_MAX;
	double max_double = DBL_MAX;
	
	printf("Size of integer: %lu bytes\n", sizeof(max_int));    
    printf("Size of   float: %lu bytes\n", sizeof(max_float));
    printf("Size of  double: %lu bytes\n\n", sizeof(max_double));	
	
	printf("Maximum value for integer: %d \n", max_int);
	printf("Maximum value for   float: %f \n", max_float);
	printf("Maximum value for  double: %f ", max_double);
	return 0;
}
