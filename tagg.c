#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
// Initialize the MPI environment
MPI_Init(NULL, NULL);

// Find out rank, size
int msg, myrank, world_size;
MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
MPI_Comm_size(MPI_COMM_WORLD, &world_size);

/////////////////////////////////////////////
if ( myrank == 0 && world_size != 1 ) {
MPI_Status status;

while (world_size - 1) {
MPI_Recv(&msg, 1, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);

if (status.MPI_TAG == 6)
world_size--;
else
printf("Root got %d from node %d\n", msg, status.MPI_SOURCE);
}
} else {
int tag = 2;

for (int i = 0; i < myrank; i++) {
msg = i + myrank;
MPI_Send(&msg, 1, MPI_INT, 0, tag, MPI_COMM_WORLD);
}

tag = 6;

MPI_Send(&msg, 1, MPI_INT, 0, tag, MPI_COMM_WORLD);
}

/////////////////////////////////////////////
MPI_Finalize();
return 0;
}