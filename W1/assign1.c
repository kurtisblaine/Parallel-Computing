#include <stdio.h>
#include <stdlib.h>

int gen();
void Fill( int A[], int N );
void Print( int A[], int N );
int Stat( int A[], int N, int T );

int main()
{
	int ar[25];
	int x;

	Fill( ar, 5 );
	Print( ar, 5 );
	x = Stat( ar, 5, 7 );
	printf("The number 7 appeared  %d times\n", x);

	return 0;
}
int gen(){
	int gen=0;
	gen  = (rand() % 9);
	return gen;
}

void Fill(int A[], int N){
	for(int i=0; i<N; i++)
		A[i] = gen();
}
void Print(int A[], int N){
	for(int i=0; i<N; i++)
                printf("the %dth value is %d\n", i, A[i]);
}
int Stat(int A[], int N, int T){
	int stat=0;

	for(int i=0; i<N; i++)
                if(A[i] == T) stat++;

	return stat;
}
