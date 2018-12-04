#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <omp.h>

int buff[10] = {3,1,1,2,5,4,2,1,1,3};
int next;


void working( int me , int mytask)
{
	int dur;
	printf("%d getting a job\n", me);

		dur = buff[mytask];
		printf("%d doing task %d ... so sleep %d\n", me, mytask, dur);
		sleep( dur );	
		printf("%d sleeping complete\n", me);

	printf("xxxxxxxxxxxxx %d\n", me);
}

int main()
{
	int i, tid;

	#pragma omp parallel for num_threads(3) private(tid)
	for (i=0; i < 10; ++i){
		tid = omp_get_thread_num();	
		working(tid,i);
	}	

	return 0;
}
