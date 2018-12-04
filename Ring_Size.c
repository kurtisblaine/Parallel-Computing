/* RING SIZE PROBLEM
*Group:
*       Brandon Widner, Brendon Traphagen, Kurt Waldner,
*       Manuel Marin, Jusin West
*Program Data:
*       can be found xxxxxxxxxxxxxxxxx
*To Run the program:   
*       mpicc ringSize.c -o ring 
*       mpirun -np P ring S
*To Run the program locally:
*       $HOME/opt/usr/local/bin/mpicc -o ring ./ringSize.c
*       $HOME/opt/usr/local/bin/mpirun -np N ./ring S
*Such that
*       P = processes
*       S = the starting node in the communication
*/     

#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv)
{

       // Initialize the MPI environment
       MPI_Init(&argc, &argv);

       // Get the number of processes
       int world_size;
       MPI_Comm_size(MPI_COMM_WORLD, &world_size);

       // Get the rank of the process
       int world_rank;
       MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

       // Get the name of the processor
       int startNode = atoi(argv[1]);
       int next = (world_rank + 1) % world_size;
       printf("%d %d %d\n", startNode, world_size, world_rank);

       int token;
       if (world_rank != startNode)
       {
               MPI_Recv(&token, 1, MPI_INT, world_rank - 1, 0,
                       MPI_COMM_WORLD, MPI_STATUS_IGNORE);
               printf("process %d received from process %d\n",
                       world_rank, world_rank - 1);
       }
       else {

       }
       MPI_Send(&token, 1, MPI_INT, next,
               0, MPI_COMM_WORLD);

       if (world_rank == startNode) {
               MPI_Recv(&token, 1, MPI_INT, startNode - 1, 0,
                       MPI_COMM_WORLD, MPI_STATUS_IGNORE);
               printf("Process %d received from process %d\n",
                       world_rank, world_size - 1);
       }

       MPI_Finalize();
}