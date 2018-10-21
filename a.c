#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include<bits/stdc++.h>
#include <iostream>
#include <numeric>

using namespace std;



__global__ void sum(int* input)				// kernel function definition
{
	const int tid = threadIdx.x;

	int step_size = 1;
	int number_of_threads = blockDim.x;		// blockDim = 4 i.e. number of threads per block = 4


	while (number_of_threads > 0)
	{
		if (tid < number_of_threads) // still alive?
		{
			const int fst = tid * step_size * 2;		//get the index in array
			const int snd = fst + step_size;			//get the index in array
			input[fst] += input[snd];

		}

		step_size <<= 1; 			// increment step_size by 1
		number_of_threads >>= 1;	//decrement number of threads by 2
	}

					// calculate average
}

int main()
{
	int count = 0 ;

	time_t t;
		    srand((unsigned)time(&t));
		cout<< "Enter the number of elements:\n" << endl;
		cin>>count;
	const int size = count * sizeof(int);


	int h[count];
	for(int i=0;i<count;i++)
		{
			h[i]=rand() % 1000;
			cout << "\t"<<h[i];

		}

	int* d;						//GPU parameter

	cudaMalloc(&d, size);		//assign memory to parameters on GPU

	cudaMemcpy(d, h, size, cudaMemcpyHostToDevice);		//copy the array from CPU to GPU
	sum <<<1, count / 2 >>>(d);							// call kernel function <<<number of blocks, number of threads= number of elements/2

	int result;

	cudaMemcpy(&result, d, sizeof(int), cudaMemcpyDeviceToHost);		// copy the result back from GPU to CPU

	cout << "\nSum is " << result << endl;

	getchar();

	cudaFree(d);		// Free the allocated memory
	//delete[] h;

	return 0;
}

