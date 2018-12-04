#include <stdio.h>

int main()
{
	int   i, n, chunk;
	int a[100], b[100], result;

	omp_set_num_threads(3);

	n = 5;
	result = 0;
	for (i=0; i < n; i++) 
	{
		a[i] = i;
		b[i] = i * 2;
	}

	#pragma omp parallel for  reduction(+:result) schedule(dynamic) 
	for (i=0; i < n; i++)
	{
		printf("%d getting %d\n", omp_get_thread_num(), i);
		result =  result + i;
	}
		//result = result + (a[i] + b[i]);

	printf("Final result= %d\n",result);

	return 0;
}
