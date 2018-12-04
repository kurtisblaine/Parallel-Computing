#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <omp.h>
#define SIZE 30

int main(){

        int list[SIZE] = {6,8,9,3,4,5,6,7,1,2,3,4,5,9,8,7,6,5,4,3,1,2,3,4,5,6,7,7,7,7};
        int counter = 0, V = 7, threads = 4, tid;

        omp_set_dynamic(0);
        omp_set_num_threads(threads);

	printf("the list:\n");	

	for(int i = 0; i <SIZE; i++)
		printf("%d ", list[i]);
	printf("\n");

#pragma omp parallel shared(threads, counter) private(tid)
{
	 tid = omp_get_thread_num();

	#pragma omp for schedule(static, SIZE/threads)

  	 for(int index = 0; index < SIZE; index++){
       		 if( list[index] == V){    
               		 counter++;
               		 printf("thread %d found V at index %d\n", tid, index);
          	  }
     	}
}
    printf("V, such that V = %d, occurs %d times in the array\n",V, counter);
    return 0;
}
