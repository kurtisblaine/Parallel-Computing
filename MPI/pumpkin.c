// Sample skeleton program for Wednesday 10/31
//    In class programming 
//    Use some of the group communication ops

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
	MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);

	/////////////////////////////////////////////	


//Proc 0:  generate & fill int [16]
//Share a portion of the list with each of the 4 nodes
	int size = 16;
	int recsize = size / world_size;
	
	int arr[size];
	int recv[ recsize];
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
		
		printf("%d calculated %d\n", myrank, partial_sum);

		int partial_sums[world_size];
		MPI_Gather(&partial_sum, 1, MPI_INT, partial_sums, 1, MPI_INT, 0, MPI_COMM_WORLD);

//Everyone find the sum of their part of the list

		if (myrank == 0){
			for (int i = 0; i <  recsize; i++){
				printf("%d's sum was %d\n", i, partial_sums[i]);
			}

			int ranks[world_size];
			
			
			for(int i =0; i < recsize; i++){
				ranks[i] = i;
			}

			for(int i =0; i <  recsize; i++){
				for(int j =0; j < recsize -1; j++){
					if(partial_sums[j] > partial_sums[j+1]) {
						int tmp = partial_sums[j];
						partial_sums[j] = partial_sums[j+1];
						partial_sums[j+1] = tmp;
						
						tmp = ranks[j];
						ranks[j] = ranks[j+1];
						ranks[j+1] = tmp;
						
					}
				}
				ranks[i] = i;
			}

			for(int i =0; i < recsize; i++){
				MPI_Send(&ranks[i], 1, MPI_INT, i, 0, MPI_COMM_WORLD);
			}
	
			int my_order;
			MPI_Recv(&my_order, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

			printf("%d's rank was %d\n", myrank, my_order);




			

//			while(){
//				int min = 0;
//				for(int i =0; i < 4; i++)
//					if(partial_sums[i] < partial_sums[min]) min = i;
//			}
		}

//Report sums back to Proc 0



//Order the processes low to high ( 0,1,2,3  ) based on sum
//Tell each process their place in the ordering
//  For example: process 2 has the lowest sum so rated 0


//All processes report their ranking in the group



	/////////////////////////////////////////////	
	MPI_Finalize();
	return 0;
}

