#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
// Initialize the MPI environment
MPI_Init(NULL, NULL);

// Find out rank, size
int msg[3], myrank, world_size;
MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
MPI_Comm_size(MPI_COMM_WORLD, &world_size);

/////////////////////////////////////////////
if ( myrank == 0 ) {
while (world_size - 1) {
MPI_Recv(&msg, 3, MPI_INT, MPI_ANY_SOURCE, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

if (msg[2] == 6)
world_size--;
else
printf("Root got %d from node %d\n", msg[1], msg[0]);
}
} else {
msg[0] = myrank, msg[2] = 2;

for (int i = 0; i < myrank; i++) {
msg[1] = i + myrank;
MPI_Send(&msg, 3, MPI_INT, 0, 0, MPI_COMM_WORLD);
}

msg[2] = 6;

MPI_Send(&msg, 3, MPI_INT, 0, 0, MPI_COMM_WORLD);
}

/////////////////////////////////////////////
MPI_Finalize();
return 0;
}