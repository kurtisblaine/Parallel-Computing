
/* RING LAP PROBLEM
*Group:
*       Kurt Waldner
*Program Data:
*       can be found /home/f18/p853/MPI1
*To Run the program:   
*       mpicc ringlap.c -o ring 
*       mpirun -np P ring N
*To Run the program locally:
*       $HOME/opt/usr/local/bin/mpicc -o ring ./ringlap.c
*       $HOME/opt/usr/local/bin/mpirun -np N ./ring S
*Such that
*       P = processes
*       N = lap
*/


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
	int laps = atoi(argv[1]);
	MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);

	/////////////////////////////////////////////	


//Proc 0:  generate & fill int [16]
//Share a portion of the list with each of the 4 nodes

	int token = 0;
	int size = 16;
	int recsize = size / world_size;
	
	int arr[size];

	int recv[ recsize];

for(int lap =1 ; lap<=laps; lap++){
	if(myrank == 0){
		for (int i = 0; i < size; i++){
			arr[i] = 15 - i;
		}
	}
	

	MPI_Scatter(arr, recsize, MPI_INT, recv, recsize, MPI_INT, 0, MPI_COMM_WORLD);

	int partial_sum = 0;

		for (int i = 0; i < recsize; i++){
			partial_sum += recv[i];
		}
		
//		printf("%d calculated %d\n", myrank, partial_sum);

		int partial_sums[world_size];
		MPI_Gather(&partial_sum, 1, MPI_INT, partial_sums, 1, MPI_INT, 0, MPI_COMM_WORLD);

//Everyone find the sum of their part of the list
		int ranks[world_size];
		if (myrank == 0){
			//token += 100;
			//for (int i = 0; i <  recsize; i++){
				//printf("%d's sum was %d\n", i, partial_sums[i]);
			//}
			
			for(int i =0; i < world_size; i++){
				ranks[i] = i;
			}

			for(int i =0; i <  world_size; i++){
				for(int j =0; j < world_size -1; j++){
					if(partial_sums[j] > partial_sums[j+1]) {
						int tmp = partial_sums[j];
						partial_sums[j] = partial_sums[j+1];
						partial_sums[j+1] = tmp;
						
						tmp = ranks[j];
						ranks[j] = ranks[j+1];
						ranks[j+1] = tmp;
						
					}
				}
			}

			for(int i =0; i < world_size; i++){
				MPI_Send(&ranks[i], 1, MPI_INT, i, 0, MPI_COMM_WORLD);}		
			}
	
			int my_order = 0;
			
//			MPI_Scatter(ranks, 1, MPI_INT, &my_order, 1, MPI_INT, 0 , MPI_COMM_WORLD);
			MPI_Recv(&my_order, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			if (myrank == 0){
				token+=100;
				printf("Rank %d token %d lap %d\n",myrank, token, lap);
			}	
			printf("%d's rank is %d\n", myrank, my_order);

}		
	/////////////////////////////////////////////	
	MPI_Finalize();
	return 0;
}

