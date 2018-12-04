#include <stdio.h>

int main()
{
	int   i, n, chunk;
	int a[100], b[100], result;

	n = 5;
	result = 0;
	for (i=0; i < n; i++) 
	{
		a[i] = i;
		b[i] = i * 2;
	}

	#pragma omp parallel for  reduction(+:result) 
	for (i=0; i < n; i++)
		result = i;
		//result = result + (a[i] + b[i]);

	printf("Final result= %d\n",result);

	return 0;
}
