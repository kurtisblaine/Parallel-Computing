#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <omp.h>

#define N  100 

int main()
{
 int A[N];
 int i, j, tmp;
 int eoro;
 int swp, tswp;

 //srand( time(NULL) );
 
 for (i = 0; i < N; ++i)
   A[i] = rand() % 500 + 1;     // random val in range 1 to 50
 A[N-1] = 3;

 for (i = 0; i < N; ++i)
   printf("%2d ", A[i]);
 printf("\n");

 swp = 0;
 for (i = 0; i < N; ++i)
 {
	tswp = 0;
	#pragma omp parallel for private(tmp) reduction(+:tswp) 
	for (j = i%2; j < N-1; j=j+2)
	{
		//printf("%2d doing %2d\n", omp_get_thread_num(), j);
		tswp++;
		usleep(10000);
		if (A[j] > A[j+1])
		{
			tmp = A[j];
			A[j] = A[j+1];
			A[j+1] = tmp;
		} 
	}

	swp = swp + tswp;

	printf("%2d: ", i);
	for (j = 0; j < N; ++j)
		printf("%2d ", A[j]);
	printf("\n");
	
 }

 for (i = 0; i < N; ++i)
   printf("%2d ", A[i]);
 printf("\n");

 printf("%d swaps\n", swp);

 return 0;
}
