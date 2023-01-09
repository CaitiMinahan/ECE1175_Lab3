#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//define different values for N=256, 512, 1024
//#define N 1024 
//#define N 256 
#define N 512 

//define matrices
float A[N][N]; 
float B[N][N];
float C[N][N];

int main()
{
	//randomly initialize the matrices:
	srand((unsigned)time(NULL)); 
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			A[i][j] = rand()/(float)RAND_MAX; //random initialization
			B[i][j] = rand()/(float)RAND_MAX;
		}
	}
		
	//set up timer
	clock_t start_time = clock(); 
		
	float B_t[N][N]; //transpose of B matrix
	
	//transpose B to optimize
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			B_t[j][i] = B[i][j]; 
		}
	}	
	
	//matrix multiplication
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			//initialize c matrix to be zero 
			C[i][j] = 0;
			for(int k=0; k<N; k++){
				C[i][j] += A[i][k] * B_t[j][k]; 
				//C[i][j] += A[i][k] * B[k][j]; 
			}
		}
	}
	
	//runtime calculation
	clock_t end_time = clock(); 
	float elapse = (float)(end_time - start_time)/CLOCKS_PER_SEC; 
	printf("elapse: %.4f seconds\n", elapse); 
	
	return 0;
}

