#include <stdio.h>
#include <omp.h>
#include <cstdlib>
#define N 100000
int main()
{
int arr[100000];
omp_set_num_threads(4);
int sum=0;
int i;
for( i=0; i<100000; i++)
arr[i] = rand()%100000;

#pragma omp parallel for reduction(+:sum)
for( i=0;i<100000; i++)
{
         sum = sum+arr[i];
    
}

printf("\nAVERAGE is  = %f", float(sum)/N);
}

/*
g++ Pavg.c -fopenmp
a.out

*/
