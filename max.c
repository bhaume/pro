#include <stdio.h>
#include <omp.h>
#include <cstdlib>
int main()
{
int arr[100000];
omp_set_num_threads(4);
int max_val=0;
int i;
for( i=0; i<100000; i++)
arr[i] = rand()% 100000;

#pragma omp parallel for
for( i=0;i<100000; i++)
{
//printf("thread id = %d and i = %d", omp_get_thread_num(), i);
if(arr[i] > max_val)
{
#pragma omp critical
    {
          max_val = arr[i];
     }
}
}
printf("\nmax_val = %d", max_val);
}





/*
 g++ Pmax.c -fopenmp
./a.out

*/
