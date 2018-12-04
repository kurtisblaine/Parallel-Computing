#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// return n % d
int mymod( int n, int d )
{
	int g;
	g = n;
		while (g >= d )
		g = g - d;

	return g;
}

int isPrime( int x )
{
	int i, g;
	int isprime = 1;

	if (x > 2 && mymod(x,2) ==0 ) return 0;
 
	for (i = 3; i <= sqrt(x); i=i+2 )
	{
		g = mymod(x, i);
		
		if (g == 0)
		   	return 0;
	}
	return 1;
}

int main( int argc, char *argv[])
{
	int i, N, isprime = 1;
	int x;

	if (argc != 2)
	   return 1;

	N = atoi(argv[1]);
	x = 0;

	for(i=2; i< N; i++){
	
	isprime = isPrime ( i );
		if (isprime){
			printf("%d ", i);
			x++;
		}
	}
	printf("\n");
	printf("Many: %d\n",x); //	isprime = isPrime( N ); " //	printf("Result %s\n", isprime==1?"Yes":"No");

	return 0;
}
