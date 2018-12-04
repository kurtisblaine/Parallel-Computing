#include <stdio.h>
#include <omp.h>

int main()
{
	int i = 0;
	int me;
	omp_set_num_threads(5);

	#pragma omp parallel  private(me) 
	{
		me = omp_get_thread_num();
		printf("Hi, from %d\n", me);
		sleep(1);

//		#pragma omp barrier

		printf("Bye, from %d\n", me);
	}
	return 0;
}

