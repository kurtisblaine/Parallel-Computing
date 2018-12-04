#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#define ROW_COUNT 6
#define COLUMN_COUNT ROW_COUNT
int arr1[ROW_COUNT][COLUMN_COUNT] = {{0, 0, 0, 0, 0, 0},
                                     {0, 1, 2, 3, 3, 0},
                                     {0, 2, 5, 9, 5, 0},
                                     {0, 2, 9, 9, 5, 0},
                                     {0, 7, 3, 4, 8, 0},
                                     {0, 0, 0, 0, 0, 0}}; 
int arr2[ROW_COUNT][COLUMN_COUNT];
int main()
{
    int i, j, result;
    time_t start, stop;
    
    
    printf("Original: \n");
    
    for( i = 1; i < ROW_COUNT - 1; i++)
    {
        for( j = 1; j < COLUMN_COUNT - 1; j++)
        {
            printf("%d \t", arr1[i][j]);
        }
        printf("\n");
    }
    
    start = clock();
    
    #pragma omp parallel
    for( i = 1; i < ROW_COUNT - 1; i++)
    {
        
       #pragma omp parallel for num_threads(4)
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
    #pragma omp barrier
    stop = clock();
    
    printf("\nResults: \n");
    
    for( i = 1; i < ROW_COUNT - 1; i++)
    {
        for( j = 1; j < COLUMN_COUNT - 1; j++)
        {
            printf("%d \t", arr2[i][j]);
        }
        printf("\n");
    }
    
    printf("\nSequential neighbor problem took %f seconds.\n", (stop-start)/(double)CLOCKS_PER_SEC);
    
    return 0;
}