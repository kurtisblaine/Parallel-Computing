#include <stdio.h>
#include <omp.h>

int main(int argc, char *argv[])
{
	int i,k;
	int tid;
	int x,y;	
	i = 0;

	omp_set_num_threads(5);

		#pragma omp parallel sections private(tid)
		{
		printf("hi\n");
		#pragma omp section
			{
		tid = omp_get_thread_num();
				printf("Section 1: %d\n", tid);
 				x = 20 + tid;
			}
		#pragma omp section
			{
		tid = omp_get_thread_num();
				printf("Section 2: %d\n", tid);
 				y = 50 + tid;
			}

		}

	printf("Done X: %d  Y: %d\n", x, y);

	return 0;
}

