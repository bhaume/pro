#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
int main()
{
int arr[100000];
omp_set_num_threads(4);
int min_val=100000;
int i;
for( i=0; i<100000; i++)
arr[i] = rand()% 10000;

#pragma omp parallel for
for( i=0;i<100000; i++)
{
//printf("thread id = %d and i = %d", omp_get_thread_num(), i);
if(arr[i] < min_val)
{
#pragma omp critical
    {
          min_val = arr[i];
     }
}
}
printf("\nmin_val = %d", min_val);
}



/*
 g++ Pmin.c -fopenmp
./a.out

*/
