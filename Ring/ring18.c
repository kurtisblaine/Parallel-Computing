
// MPI practice prorgram 10/24

//for exactly 4 nodes
// pass the token around to each process
//  0 to 1 to 2 to 3 ... and back to 0


#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	//everyone has a variable if it is declared up here
	// Initialize the MPI environment
	MPI_Init(NULL, NULL);

	// Find out rank, size
	int my_rank;
	int world_size;
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);

	/* sample code from your example on Monday
	MPI_Send(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
	MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
	*/

/////////////////////////////////////////////
	//every node is doing this code
	//if a variable is declared down here it is local to the process
	int token;

	if ( my_rank == 0 )
	{
		printf("Proc 0 of %d %d \n", my_rank, world_size);
		token = 42;
		MPI_Send(&token, 1, MPI_INT, (my_rank+1)%world_size, 0, MPI_COMM_WORLD);
		MPI_Recv(&token, 1, MPI_INT, world_size-1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		printf("token at %d with value %d\n",0,token);
	}
	else
	{
		MPI_Recv(&token, 1, MPI_INT, my_rank-1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		printf("%d has token %d\n", my_rank, token);

		token++;
		if (my_rank < world_size-1){
//			MPI_Send(&token, 1, MPI_INT, my_rank+1, 0, MPI_COMM_WORLD);
			MPI_Send(&token, 1, MPI_INT, (my_rank+1)%world_size, 0, MPI_COMM_WORLD);

		}
		else{
			MPI_Send(&token, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
		}
	}			

/////////////////////////////////////////////
	MPI_Finalize();
	return 0;
}

