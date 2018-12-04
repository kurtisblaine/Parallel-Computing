/* LISTER PROBLEM
*Name:
*	Kurt Waldner
*Program Data:
*       can be found /home/f18/p853/MPI1
*To Run the program:
*       mpicc lister.c -o list
*       mpirun -np P list
*To Run the program locally:
*       $HOME/opt/usr/local/bin/mpicc -o list ./lister.c
*       $HOME/opt/usr/local/bin/mpirun -np N ./list
*Such that
*       P = processes
*/

#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#define MAX 100
#define RANGE 10
int main(int argc, char* argv[]) {

        MPI_Init(NULL, NULL);
        srand(time(0));

        int my_rank, world_size, sum, max;
        int p[RANGE],partialList[MAX],bigList[MAX],recv[RANGE],pfinal[MAX], ptemp[3];
        int min = MAX;

        MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
        MPI_Comm_size(MPI_COMM_WORLD, &world_size);

         if( my_rank == 0)
        {
               partialList[0] = 10;
               partialList[1] = 20;
        }

        MPI_Bcast(&partialList, 2, MPI_INT, 0, MPI_COMM_WORLD);

        for(int i = 0; i < RANGE; i++){
                p[i] = my_rank + rand()%( MAX );
                printf("process %d: generated %d\n", my_rank, p[i] );
        }

        MPI_Gather(p, RANGE, MPI_INT, bigList, RANGE, MPI_INT, 0, MPI_COMM_WORLD);

        MPI_Scatter(bigList, RANGE, MPI_INT, recv, RANGE, MPI_INT, 0, MPI_COMM_WORLD);

        for(int i = 0; i < RANGE; i++){
                sum += recv[i];
                if(recv[i] > max)
                        max = recv[i];
                if(recv[i] < min)
                        min = recv[i];
        }

        ptemp[0] = sum;
        ptemp[1] = max;
        ptemp[2] = min;

        MPI_Gather(ptemp, 3, MPI_INT, pfinal, 3, MPI_INT, 0, MPI_COMM_WORLD);

	if(my_rank == 0){
		printf("Process 0 gathered from workers\n");
        	for(int i = 0; i < world_size*3; i += 3)
            	   	 printf("Process%d:\n sum:%d\n max: %d\n min: %d\n",i/3, pfinal[i], pfinal[i+1], pfinal[i+2]);
	}
           MPI_Finalize();
           return 0;
}
