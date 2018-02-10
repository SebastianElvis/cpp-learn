/**
 * Copyright 1993-2012 NVIDIA Corporation.  All rights reserved.
 *
 * Please refer to the NVIDIA end user license agreement (EULA) associated
 * with this source code for terms and conditions that govern your use of
 * this software. Any use, reproduction, disclosure, or distribution of
 * this software and related documentation outside the terms of the EULA
 * is strictly prohibited.
 */
#include <stdio.h>

const int N = 16;

// name             executed by           invoked by
// __device__        device                 device
// __global__        device                 host
// __host__          host                   host


// Every thread executes this kernel function simultaneously
// so called SIMT
__global__
void vector_add(int *a, int *b, int *res)
{
	// blockIdx: block id
	// blockDim: threads per block
	// threadIdx: thread id
	int i = blockIdx.x *blockDim.x + threadIdx.x;
	res[i] = a[i] + b[i];
}

void init(int x[])
{
	for(int i=0;i<N;i++){
		x[i] = i;
	}
}

int main()
{
	int a[N];
	int b[N];
	int res[N];

	init(a);
	init(b);

	int *ad, *bd, *resd;
	int copy_size = N*sizeof(int);

	cudaMalloc(&ad, copy_size);
	cudaMalloc(&bd, copy_size);
	cudaMalloc(&resd, copy_size);
	cudaMemcpy(ad, a, copy_size, cudaMemcpyHostToDevice);
	cudaMemcpy(bd, b, copy_size, cudaMemcpyHostToDevice);

	// kernel_func<<<numBlock, numThread, Ns, S>>>()
	// <<<numBlock, numThread, Ns, S>>>
	// Ns, S optional
	// Ns: the maximum dynamic memory size
	// the kernel function is in the stream S


	//vector_add<<<N, 1>>>(ad, bd, resd); // Totally 1xN=N threads, it works!
	//vector_add<<<1, N>>>(ad, bd, resd); // Totally 1xN=N threads, it works!
	//vector_add<<<1, (N-1)>>>(ad, bd, resd); // Totally (N-1) threads, so omits the last element...
	vector_add<<<4, 4>>>(ad, bd, resd); // Totally 4x4=N(16) threads, it works!
	cudaMemcpy(res, resd, copy_size, cudaMemcpyDeviceToHost);

	cudaFree(ad);
	cudaFree(bd);
	cudaFree(resd);

	for(int i=0;i<N;i++){
		printf("%d ", res[i]);
	}
	return EXIT_SUCCESS;
}
