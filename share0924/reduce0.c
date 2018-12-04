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

	for (i=0; i < n; i++)
		result = result + (a[i] + b[i]);

	printf("Final result= %d\n",result);

	return 0;
}
