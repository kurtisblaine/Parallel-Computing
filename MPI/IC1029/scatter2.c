
// same as scatter.c
//   but the receiver does not have to 
//   include the sending buffer in call


#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) 
{
	// Initialize the MPI environment
	MPI_Init(NULL, NULL);

	// Find out rank, size
	int myrank;
	int world_size;
	int vals[100];
	int myvals[100];
	int N, M, X, i;
	MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);

	/////////////////////////////////////////////	
	if ( myrank == 0 )
	{
		N = 16;
		for ( i = 0; i < N; ++i )
		{
			vals[i] = 10 + i;
			printf("%2d ", vals[i]);
		}
		printf("\n");


    	MPI_Scatter(vals, 4, MPI_INT,
					myvals, 4, MPI_INT,
					0, MPI_COMM_WORLD);
	}
	else
	{
    	MPI_Scatter(NULL, 4, MPI_INT,
					myvals, 4, MPI_INT,
					0, MPI_COMM_WORLD);
	}

int sum = 0;
	for ( i = 0; i < 4; ++i ) 
	{
		sum = sum + myvals[i];
		printf("Proc: %2d    i: %2d     val: %2d\n", 
					myrank, i, myvals[i]);
	}	
printf("%d reporst sum %d\n", myrank, sum);
	/////////////////////////////////////////////	
	MPI_Finalize();
	return 0;
}





