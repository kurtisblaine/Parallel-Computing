/* RING SIZE PROBLEM
*Group:
*       Brandon Widner, Brendon Traphagen, Cody Schroeder, Kurt Waldner,
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

#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
        //everyone has a variable if it is declared up here
        // Initialize the MPI environment
        MPI_Init(&argc, &argv);

        // Find out rank, size
        int my_rank,world_size,token,startNode;
        startNode = atoi(argv[1]);

        MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
        MPI_Comm_size(MPI_COMM_WORLD, &world_size);

        int nextProcess = (startNode + 1) % world_size;
        int previousProcess = (startNode + world_size - 1) % world_size;

        /* sample code from example on Monday
        MPI_Send(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        */

/////////////////////////////////////////////
        //every node is doing this code
        //if a variable is declared down here it is local to the process

        if ( my_rank == 0 )
        {      
                //initalize token which will the amount of loops
                token = world_size;
                //print process/world size
                printf("Proc %d of %d \n", startNode, world_size);
                //changes to two bc two integers in array
                MPI_Send(&token, 1, MPI_INT, nextProcess, 0, MPI_COMM_WORLD);
                //MPI_Recv(&token, 1, MPI_INT, world_size-1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                printf("process %d sent to %d with value %d\n",startNode,nextProcess,token);

        }

        
           /* MPI_Recv(&token, 1, MPI_INT, nextProcess, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            MPI_Send(&token, 1, MPI_INT, startNode, 0, MPI_COMM_WORLD);
            MPI_Abort( MPI_COMM_WORLD, 0 );*/
        while(1){
                //keep passing the message until returning back to sender
                MPI_Recv(&token, 1, MPI_INT, nextProcess, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                if(my_rank == 0){
                    token--;
                    printf("Process %d end %d\n",my_rank, token);
                }
            
                //send the token along
                MPI_Send(&token, 1, MPI_INT, nextProcess, 0, MPI_COMM_WORLD);
                printf("process %d sent to %d with value %d\n",startNode,nextProcess,token);

                if(token == 0){
                     printf("Process %d terminating\n", my_rank);
                     MPI_Abort( MPI_COMM_WORLD, 0 );
                     break;
                }

        }       

            MPI_Send(&token, 1, MPI_INT, startNode, 0, MPI_COMM_WORLD);
            printf("process %d sent to %d with value %d\n",startNode,nextProcess,token);  

/////////////////////////////////////////////
                MPI_Finalize();
                return 0;
        }
