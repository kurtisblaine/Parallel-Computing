
/*********************************************************************************
 * Matrix Multiplication openMP
 *
 * Group 1: Brandon Widner, Brendon Traphagen, Cody Schroeder, Kurt Waldner,
 * Manuel Marin, Jusin West
 *
 * Matrix multiplication
 * Use a square matrix
 * each element of the first row of the first matrix is multiplied by each
 * element on the first column of the second matrix. The results are added.
 *
 * To use, the program takes three command line arguments, a max random value,
 * the seed, and the size, but there are default values if you decide otherwise.
 *********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>


void alloc_matrices(int ***m1, int ***m2, int ***m3, int size)
{
  int i;
  *m1 = (int **) malloc(sizeof(int *) * size);
  *m2 = (int **) malloc(sizeof(int *) * size);
  *m3 = (int **) malloc(sizeof(int *) * size);

  for(i = 0; i < size; ++i)
  {
    (*m1)[i] = (int *) malloc(sizeof(int) * size);
    (*m2)[i] = (int *) malloc(sizeof(int) * size);
    (*m3)[i] = (int *) malloc(sizeof(int) * size);
  }
}

void init_matrices(int ***m1, int ***m2, int ***m3, int size, int max_rand)
{
  int i, j;
  alloc_matrices(m1, m2, m3, size);

  for(i = 0; i < size; ++i)
  {
    for(j = 0; j < size; ++j)
    {
      (*m1)[i][j] = (rand() % max_rand + 1);
      (*m2)[i][j] = (rand() % max_rand + 1);
      (*m3)[i][j] = 0;
    }
  }
}


void print_matrix(int **m, int size)
{
  int i, j;

  for(i = 0; i < size; ++i)
  {
    for(j = 0; j < size; ++j)
    {
      printf("%4d ", m[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}


void matrix_mult(int **m1, int **m2, int ***m3, int size)
{
  int i, j, k;

  for(i = 0; i < size; ++i)
  {
    for(j = 0; j < size; ++j)
    {
      for(k = 0; k < size; ++k)
      {
        (*m3)[i][j] += m1[i][k] * m2[k][j];
      }
    }
  }
}


int main(int argc, char *argv[]){
	int tid,size,max_rand,seed;
	int **m1, **m2, **m3;
	time_t start, stop;

	//change features
	size = 10;
	max_rand = 6;
	seed = 31;
	//change features

	if(argc == 4)
	  {
    		max_rand = atoi(argv[1]);
    		seed = atoi(argv[2]);
    		size = atoi(argv[3]);
  	 }	

	printf("args:\n%d\n%d\n%d\n\n", max_rand, seed, size);
	
	init_matrices(&m1,&m2, &m3, size, max_rand);
	printf("MATRIX 1\n\n");
	print_matrix(m1,size);
	printf("MATRIX 2\n\n");	
	print_matrix(m2,size);
	start = clock();

	#pragma omp parallel for num_threads(size) private(tid)
	for(int x = 0; x < (size); x++) //Create threads and do work
	{
		tid = omp_get_thread_num();
		matrix_mult(m1, m2, &m3, size);
	}
	#pragma omp barrier
	stop = clock();

	printf("MATRIX 3\n\n");
	print_matrix(m3,size);
	printf("Multiplication with openMP, size: %d,  took %f seconds.\n",size,  (stop-start)/(double)CLOCKS_PER_SEC); //Print time

	return 0;
}

