#include <stdio.h>
#include <time.h>
#include <pthread.h>

#define ROW_COUNT 3 //Change me as needed
#define COLUMN_COUNT ROW_COUNT //Assuming square matrices of the same size

void* matrixPthreads(void *Input);

int matrix1[ROW_COUNT][COLUMN_COUNT] = {{1,5,9},{10,2,-6},{100,12,1}}; //Assign values as needed
int matrix2[ROW_COUNT][COLUMN_COUNT] = {{6,7,2},{8,9,3},{20,17,4}}; //Assign values as needed
int matrix3[ROW_COUNT][COLUMN_COUNT];

pthread_mutex_t debugLock; //As name suggests, only used for debugging
pthread_barrier_t timingBarrier;

int main()
{
	pthread_mutex_init(&debugLock,NULL);
	pthread_barrier_init(&timingBarrier,NULL,(ROW_COUNT * COLUMN_COUNT) + 1); //+ 1 for main()
	pthread_t threadId[(ROW_COUNT * COLUMN_COUNT)];
	time_t start, stop;

	start = clock();
	for(long x = 0; x < (ROW_COUNT * COLUMN_COUNT); x++) //Create threads
	{
		pthread_create(&threadId[x], NULL, matrixPthreads, (void*)x);
	}
	pthread_barrier_wait(&timingBarrier); //Wait for all work to be done before stopping clock + printing results
	stop = clock();

	for(int y = 0; y < ROW_COUNT; y++) //Print results
	{
		printf("|");
		for(int x = 0; x < ROW_COUNT; x++)
		{
			printf(" %5d", matrix3[y][x]);
		}
		printf("|\n");
	}
	printf("Multiplication with pthreads took %f seconds.\n", (stop-start)/(double)CLOCKS_PER_SEC); //Print time

	return 0;
}

void* matrixPthreads(void *Input)
{
	long myId = (long)Input;
	int myRow = 0;
	int myColumn = 0;
	int total = 0;

	for(int x = 0; x < myId; x++) //Calculate destination based on thread ID
	{
		myColumn++;
		if(myColumn == COLUMN_COUNT)
		{
			myColumn = 0;
			myRow++;
		}
	}

	for(int x = 0; x < COLUMN_COUNT; x++)
	{
		total += matrix1[myRow][x] * matrix2[x][myColumn];
	}
	/*
	pthread_mutex_lock(&debugLock); //Locked to maintain nice formatting
	printf("DEBUG: My ID is: %d\nMy \"coordinates\" are: %d,%d\nMy total is: %d\n\n",myId,myRow,myColumn,total);
	pthread_mutex_unlock(&debugLock);
	*/
	matrix3[myRow][myColumn] = total;
	pthread_barrier_wait(&timingBarrier);
	pthread_exit(NULL);
}
