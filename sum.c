#include <stdio.h>
#include <omp.h>
#include <cstdlib>
int main()
{
int arr[100000];
omp_set_num_threads(4);
int sum=0;
int i;
for( i=0; i<100000; i++)
arr[i] = 1;

#pragma omp parallel for reduction(+:sum)
for( i=0;i<100000; i++)
{
         sum = sum+arr[i];
    
}

printf("\nSUM is  = %d", sum);
}
/*
g++ Psum.c -fopenmp
./a.out

*/
