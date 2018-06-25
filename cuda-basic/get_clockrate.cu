#include <stdio.h>



int get_GPU_Rate()
{
 cudaDeviceProp deviceProp;
 cudaGetDeviceProperties(&deviceProp,0);
 return deviceProp.clockRate;
}

int main() {
	printf("GPU Rate is %d\n", get_GPU_Rate());
}
