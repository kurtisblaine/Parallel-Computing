
/*
Generate 10 random numbers and send
  a) gen 1 value, send immediately
      -- we'll put a short sleep in each program
          to make the behavior more obvious

  b) gen 10, then send 1 at a time

  c) gen 10, sent all at once
*/

#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) 
{
  int world_rank;
  int world_size;
  int number;
  int k,x;
int a[10];  

  MPI_Init(NULL, NULL);
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);

  // Must have 2 processes 
  if (world_size != 2)  
  {
    fprintf(stderr, "World size must be 2 for %s\n", argv[0]);
    MPI_Abort(MPI_COMM_WORLD, 1); 
  }





  if (world_rank == 0) 
  {
   for(k=0; k <10; ++k) {
   a[k] = rand() %50 +1;
    }
 MPI_Send(a, 10, MPI_INT, 1, 0, MPI_COMM_WORLD);
 } 



  else if (world_rank == 1)  
  {
   MPI_Recv(a, 10, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
for(k=0;k<10;++k) 
    printf("Process 1 received number %d from process 0\n", a[k]);
}

  MPI_Finalize();

}
