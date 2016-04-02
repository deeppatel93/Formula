///
//  formula
//

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <sys/time.h>
#include "nCr.h"

/*

int factorial(int n){
	if(n == 1){
		return 1;
	}
	return (n * factorial(n - 1));
	
}

int nCr(int n, int r){
	
	return (factorial(n)/ (factorial(r) * factorial(n-r)));
}
*/

  
int main(int argc, char ** argv){
	//check for extra arguements
	if(argc != 2){ 
		fprintf(stderr, "Incorrect number of arguements\n");
		return -1;
	}
	char *input = argv[1];
	int j ;
	
	//check for usage flag
	if(strlen(input) > 1){
		if(input[0] == '-' && input[1] == 'h'){
			fprintf(stderr, "Usage: formula <positive integer>\n\n");
			return -1;
		} 
	}
	//check for error	
	for(j = 0; j < strlen(input); j++){
		if(isdigit(input[j]) == 0){
			fprintf(stderr, "Incorrect input\n\n");
			return -1;
		} 
	}
	struct timeval start, end;
	int val = atoi(argv[1]);
	if(val < 0){
		fprintf(stderr, "Incorrect input \n\n");
		return -1;
	}
	if(val > 20){
		fprintf(stderr, "Overflow\n\n");
		return 0;
	}
	//check for overflow
	
	printf("(1 + x)^%d =  1", val);
	gettimeofday(&start, NULL);
	
	
	//calculates coeffecient and prints it
	if(val == 0){ 
		printf("\n");
		gettimeofday(&end, NULL);
		printf("%ld Milliseconds \n", ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec)));
		return 0;
	}
	else{ 
		int i;
		int coeff;
		for(i = 1; i <= val; i++){
			coeff = nCr(val, i);
			printf(" + %d*x^%d", coeff, i);
		}
		printf("\n");
	}
	gettimeofday(&end, NULL);
	//prints time
	printf("%ld Milliseconds \n", ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec)));
	
	return 0;
}