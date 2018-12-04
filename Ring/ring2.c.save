
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
	int token[2];

	if ( my_rank == 0 )
	{
		printf("Proc 0 of %d %d \n", my_rank, world_size);
		token[0] = 42;
		token[1] = world_size-2;
		//changes to two bc two integers in array
		MPI_Send(&token, 2, MPI_INT, my_rank+1, 0, MPI_COMM_WORLD);
		MPI_Recv(&token, 2, MPI_INT, world_size-1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		printf("token at %d with value %d\n",0,token[0]);
	}
	else
	{
		MPI_Recv(&token, 2, MPI_INT, my_rank-1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		
		if(token[1] == my_rank){
			printf("Got it----%d has token %d\n", my_rank, token[0]);
			token[1] = -1;
		}

			MPI_Send(&token, 2, MPI_INT, (my_rank+1)%world_size, 0, MPI_COMM_WORLD);

	}			

/////////////////////////////////////////////
	MPI_Finalize();
	return 0;
}

