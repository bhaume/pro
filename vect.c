#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include<bits/stdc++.h>
#include <iostream>
#include <numeric>

using namespace std;



__global__ void sum(int* input)				
{
	const int tid = threadIdx.x;

	int step_size = 1;
	int number_of_threads = blockDim.x;		


	while (number_of_threads > 0)
	{
		if (tid < number_of_threads) 
		{
			const int fst = tid * step_size * 2;		
			const int snd = fst + step_size;			
			input[fst] += input[snd];

		}

		step_size <<= 1; 			
		number_of_threads >>= 1;	
	}

					
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

	int* d;						

	cudaMalloc(&d, size);		

	cudaMemcpy(d, h, size, cudaMemcpyHostToDevice);		
	sum <<<1, count / 2 >>>(d);							of threads= number of elements/2

	int result;

	cudaMemcpy(&result, d, sizeof(int), cudaMemcpyDeviceToHost);		

	cout << "\nSum is " << result << endl;

	getchar();

	cudaFree(d);		
	//delete[] h;

	return 0;
}
