/* *
 * Copyright 1993-2012 NVIDIA Corporation.  All rights reserved.
 *
 * Please refer to the NVIDIA end user license agreement (EULA) associated
 * with this source code for terms and conditions that govern your use of
 * this software. Any use, reproduction, disclosure, or distribution of
 * this software and related documentation outside the terms of the EULA
 * is strictly prohibited.
 */
#include <stdio.h>
#include <stdlib.h>

#define N 16

void init_mat(int mat[N][N]){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			mat[i][j] = rand() % 100;
		}
	}
}

void init_i(int mat[N][N]){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(i == j) mat[i][j] = 1;
			else mat[i][j] = 0;
		}
	}
}

void init_zeros(int mat[N][N]){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			mat[i][j] = 0;
		}
	}
}

void matmul(int a[N][N], int b[N][N], int c[N][N]){
	for(int bcol=0;bcol<N;bcol++){
		for(int arow=0;arow<N;arow++){
			for(int acol=0;acol<N;acol++){
				c[arow][bcol] += a[arow][acol] * b[acol][bcol];
			}
		}
	}
}

void print_mat(int mat[N][N]){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			printf("%3d ", mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

/**
 * Host function that prepares data array and passes it to the CUDA kernel.
 */
int main(void) {
	int a[N][N], b[N][N], c[N][N];

	init_mat(a);
	init_i(b);
	init_zeros(c);

	print_mat(a);
	print_mat(b);
	print_mat(c);

	matmul(a, b, c);
	print_mat(c);
}
