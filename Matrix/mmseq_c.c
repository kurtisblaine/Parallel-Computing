/*********************************************************************************
 * Matrix Multiplication Sequential
 *
 * Group 1: Brandon Widner, Brendon Traphagen, Cody Schroeder, Kurt Waldner,
 * Manuel Marin, Jusin West
 *
 * Matrix multiplication
 * Use a square matrix
 * each element of the first row of the first matrix is multiplied by each
 * element on the first column of the second matrix. The results are added.
 *
 *
 * To use, the program takes three command line arguments, a max random value,
 * the seed, and the size, but there are default values if you decide otherwise.
 *********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

int main(int argc, char *argv[])
{
  printf("args:\n%s\n%s\n%s\n", argv[1], argv[2], argv[3]);

  int max_rand = 6;
  int seed = 31;
  int size = 6;
  clock_t start, stop;
  
  if(argc == 6)
  {
    printf("ok\n");
    max_rand = atoi(argv[1]);
    seed = atoi(argv[2]);
    size = atoi(argv[3]);
  }

  int **m1, **m2, **m3;
  srand(seed);
  init_matrices(&m1, &m2, &m3, size, max_rand);
  print_matrix(m1, size);
  print_matrix(m2, size);
  start = clock();
  matrix_mult(m1, m2, &m3, size);
  stop = clock();
  print_matrix(m3, size);
  printf("Sequential multiplicaiton took %f seconds.\n", (stop - start) / (double) CLOCKS_PER_SEC);
  return 0;
}