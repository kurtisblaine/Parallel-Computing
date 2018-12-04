
// CSC 410
// Starting sample file:  Wed 8/29 
// the thread library is -lpthread
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUMT 8
int x = 10;

// void function with 1 void paramater
//then you must type cast in the funciton
void *sayhi ( void* param  ){
	//convert the void and type casting it to be a long and assigning it to a long
	long myid = (long) param;
	long val;

	//prints a long integer
	printf("hi %ld\n", myid);
	printf("%ld sees x as %d\n",myid, x);

	val = myid * 10;
	//exits the pthread library
	//returns a value back
	pthread_exit((void*) val);
}


int main()
{
	//define thread array
	pthread_t tid[NUMT];
	void *status;
	long i;

	printf("In main: time to build threads\n");

	for(i = 0; i < NUMT; i++ )
	{
	 printf("Creating %ld\n", i);

	//pass by reference is the &
	//first param  is the reference where to store the thread id
	//third the function to call when thread is created
	//fourth is the paramater being passed to the sayhi function
	//give the thread a unique id then do work in the funciton sayhi
	//must type cast the parameter
	pthread_create( &tid[i], NULL, sayhi, (void *)i );
	}

	printf("In main: all threads created\n");

	for(i = 0; i < NUMT; i++)
	{
	 printf("   Main: joined %d\n", i);
	//this function waits to get a signal from the other thread and then joins them
	//kind of like the wait funciton.1
	 pthread_join( tid[i], &status );
	printf("Thread %d had %ld\n", i, (long)status);
	}

	printf("In main:  all threads joined\n");

	return 0;
}


ç
