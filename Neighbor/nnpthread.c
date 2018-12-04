#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define ROW_COUNT 6
#define COLUMN_COUNT ROW_COUNT

int arr1[ROW_COUNT][COLUMN_COUNT] = 					{{0, 0, 0, 0, 0, 0},
									 {0, 1, 2, 3, 3, 0},
									 {0, 2, 5, 9, 5, 0},
									 {0, 2, 9, 9, 5, 0},
									 {0, 7, 3, 4, 8, 0},
									 {0, 0, 0, 0, 0, 0}};
int arr2[ROW_COUNT][COLUMN_COUNT];

void *work(void* param)
{
	long i, j, result;

//	printf("\nIn work");

	for( i = 1; i < ROW_COUNT - 1; i++)
	{
		for( j = 1; j < COLUMN_COUNT - 1; j++)
		{
			result = arr1[i][j] + arr1[i-1][j-1] + arr1[i-1][j] + arr1[i-1][j+1] + arr1[i][j-1] + arr1[i][j+1]
			+ arr1[i+1][j-1] + arr1[i+1][j] + arr1[i+1][j+1];

				if(result % 10 == 0)
					arr2[i][j] = 0;

				else if (result < 50)
					arr2[i][j] = (arr1[i][j]) + 3;

				else if (result > 50 && result < 150)
				{
					arr2[i][j] = (arr1[i][j]) - 3;

					if (arr2[i][j] < 0)
						arr2[i][j] = 0;
				}

				else if (result > 150)
					arr2[i][j] = 1;
		}
	}
}

int main ()
{
	long i, j;
	pthread_t tid[ROW_COUNT];
	time_t start, stop;

	printf("Original:\n");

	for( i = 1; i < ROW_COUNT - 1; i++)
	{
		for( j = 1; j < COLUMN_COUNT - 1; j++)
		{
			printf("%d ", arr1[i][j]);
		}
		printf("\n");
	}

	start = clock();

	for(i = 0; i < ROW_COUNT; i++)
	{
//		printf("Creating %ld\n", i);

		pthread_create( &tid[i], NULL, work, (void*) i);
	}


	for (i = 0; i < ROW_COUNT; i++)
	{
//			printf("	Main: joined %d\n", i);

			pthread_join( tid[i], NULL);
	}

	stop = clock();

	printf("\nResults:\n");

	for( i = 1; i < ROW_COUNT - 1; i++)
	{
		for( j = 1; j < COLUMN_COUNT - 1; j++)
		{
			printf("%d ", arr2[i][j]);
		}
		printf("\n");
	}

	printf("\npThread neighbor problem took %f seconds.\n", (stop-start)/(double)CLOCKS_PER_SEC);

	return 0;
}
