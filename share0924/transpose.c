#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define N  10 

int main()
{
 int A[N];
 int i, j, tmp;
 int eoro;
 int swp;

 //srand( time(NULL) );
 
 for (i = 0; i < N; ++i)
   A[i] = rand() % 500 + 1;     // random val in range 1 to 50
 A[N-1] = 3;

 printf("     ");
 for (i = 0; i < N; ++i)
   printf("%3d ", A[i]);
 printf("\n");

 swp = 0;
 for (i = 0; i < N; ++i)
 {
	for (j = i%2; j < N-1; j=j+2)
	{
		swp++;
		//usleep(10000);
		if (A[j] > A[j+1])
		{
			tmp = A[j];
			A[j] = A[j+1];
			A[j+1] = tmp;
		} 
	}

	printf("%3d: ", i);
	for (j = 0; j < N; ++j)
		printf("%3d ", A[j]);
	printf("\n");

 }

 printf("     ");
 for (i = 0; i < N; ++i)
   printf("%3d ", A[i]);
 printf("\n");

 printf("%d swaps\n", swp);

 return 0;
}
