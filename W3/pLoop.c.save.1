// CSC 410
// Starting sample file:  Wed 9/6 

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int globX;

void *sayhi( void *param)
{
	int myid;
	int j;
	myid  =  (long) param ;

	globX++;
	
	for ( j = 0; j < 10000 * rand() % 10; ++j)
		;

 	printf("       -- hi from %d  see global %d\n", myid, globX);
	pthread_exit(NULL);	
}

int main()
{
	pthread_t tid[5];
	void *status;
	int i;

	srand(time(NULL));	
	globX = 25;

	printf("In main: time to build threads\n");
	printf("Global1:  %d\n", globX);
	for ( i = 0; i < 5; ++i)
	{
		printf("   In main: creating thread %d\n", i);
		pthread_create( &tid[i], NULL, sayhi, (void *)(long) i );
	}
	printf("In main: all threads created\n");

	for ( i = 0; i < 5; ++i)
	{ 
		pthread_join( tid[i], &status );
		printf("   Main: joined %d\n", i);
	}

	printf("In main:  all threads joined\n");
	printf("Global9:  %d\n", globX);
	
	return 0;
}

