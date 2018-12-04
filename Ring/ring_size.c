nclude <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char* argv[]) {
        //everyone has a variable if it is declared up here
        // Initialize the MPI environment
        int token[10] = {8,7,9,6,5,4,3,2,1,0};
        int toprocess = 0, count = 0, sendto=0, getfrom= 0, start = atoi(argv[1]);

        //MPI_Init(NULL, NULL);

        MPI_Init(&argc, &argv);
        // Find out rank, size
        //int token[10] = {8,7,9,6,5,4,3,2,1};
        int my_rank;
        int world_size;
        MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
        MPI_Comm_size(MPI_COMM_WORLD, &world_size);


        if( my_rank == start)
        {
                sendto = start;

                printf("Process %d sees number %d \n", my_rank, token[sendto]);
                count ++;
                //printf("Hop %d\n", count);
                sendto =(token[sendto]);

        //      MPI_Send(&token, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
                MPI_Send(&count, 1, MPI_INT, sendto, 0, MPI_COMM_WORLD);
                //getfrom = world_size;
                MPI_Recv(&count ,1, MPI_INT, world_size - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

                //printf("Process %d sees number %d in the array first\n", 0  , token[0]);



        }

        else{


                MPI_Recv(&count, 1, MPI_INT, sendto-1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

                printf("Process %d sees number %d\n", my_rank, token[my_rank]);
                //count += 1;
                count++;
                //printf("Hop %d\n", count);
                if(token[my_rank] == 0)
                {
                printf("Total hops %d\n", count);
                MPI_Abort(MPI_COMM_WORLD, 0);
                }
                else
                //getfrom = token[my_rank]-1;
                sendto = (token[my_rank])-1;
                //printf("Send to %d  get from %d", sendto, getfrom);

                MPI_Send(&count, 1, MPI_INT,(sendto+1)%world_size, 0, MPI_COMM_WORLD);




        }


                MPI_Finalize();
                return 0;
        }
