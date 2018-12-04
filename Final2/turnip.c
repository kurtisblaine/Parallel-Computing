/*
*	Kurt Waldner
*Program Data:
*       can be found /home/f18/p853/Final2
*To Run the program:
*       mpicc turnip.c -o turnip
*       mpirun -np P turnip
*To Run the program locally:
*       $HOME/opt/usr/local/bin/mpicc -o list ./lister.c
*       $HOME/opt/usr/local/bin/mpirun -np N ./list
*Such that
*       P = processes
*/

#include <mpi.h>
#include <stdio.h>
#include <string.h>
#define MAX 15
#define RANGE 10

int main(int argc, char* argv[]) {
        MPI_Init(NULL, NULL);
	int my_rank, world_size, destination, source, turnipSize; 
	int data[MAX + 1];

	MPI_Status status;
        MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
        MPI_Comm_size(MPI_COMM_WORLD, &world_size);

        rand(my_rank);
 
	if(my_rank == 0){
		int index, i;
		for(index = 0; index < RANGE; index++){
			//generate the random destination 
			destination = (rand(0) % (world_size - 1)) +1;
			data[0] = rand(0) % MAX;
			
			//send the turnip
			MPI_Send(&data, 1, MPI_INT, destination, 0, MPI_COMM_WORLD);
			printf("process %d sent turnip \n", my_rank);

			MPI_Recv(&data, MAX+1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
			printf("process %d recieved turnip\n", data[index]) ;
			
			MPI_Get_count(&status, MPI_INT, &turnipSize);

			for(i = 1; i < turnipSize; i++) printf("%d to ", data[i]);
			printf("0\n");
			data[0] = -1;

			for(destination = 1; destination < world_size; destination++)
				MPI_Send(&data, 1, MPI_INT, destination, 0, MPI_COMM_WORLD);
			
		}
	}
	else{
		int done = 0;
		while (!done){
			MPI_Recv(&data, MAX+1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
			if(data[0]== -1) done =1;
			else{
				if(data[0] == 0) destination = 0;
				else while ((destination = ( rand( 0 ) % ( world_size - 1 ) ) + 1 ) == my_rank);
				
				data[0]--;
				data[turnipSize] = my_rank;

				MPI_Send(&data, turnipSize+1, MPI_INT, destination, 0, MPI_COMM_WORLD);
			}
		}
	}

           MPI_Finalize();
	   return 0;
}

