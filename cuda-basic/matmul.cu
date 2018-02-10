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

void print_mat(int mat[N][N]){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			printf("%3d ", mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void print_mat2(int *mat){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			printf("%3d ", mat[i*N+j]);
		}
		printf("\n");
	}
	printf("\n");
}

__global__
void mat_mul(int *x, int *y, int *z){
	int id = blockIdx.x *blockDim.x + threadIdx.x;
	int row = id/N;
	int col = id%N;
	z[row*N+col] = 0;
	for(int i=0;i<N;i++){
		z[row*N+col] += x[row*N+i] * y[i*N+col];
	}
}

int main(void) {
	int x[N][N], y[N][N], z[N][N];

	// cannot be prined
	// device functions cannot invoke host functions
	// otherwise add __device__ before the function you want to invoke
	int *xd, *yd, *zd;

	int mat_size = N*N*sizeof(int);

	init_mat(x);
	init_i(y);
	init_zeros(z);

	print_mat(x);

	cudaMalloc(&xd, mat_size);
	cudaMalloc(&yd, mat_size);
	cudaMalloc(&zd, mat_size);

	cudaMemcpy(xd, x, mat_size, cudaMemcpyHostToDevice);
	cudaMemcpy(yd, y, mat_size, cudaMemcpyHostToDevice);
	cudaMemcpy(zd, z, mat_size, cudaMemcpyHostToDevice);


	mat_mul<<<N, N>>>(xd, yd, zd);

	cudaMemcpy(z, zd, mat_size, cudaMemcpyDeviceToHost);

	print_mat(z);
}
