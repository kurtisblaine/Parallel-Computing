
// CSC 410
// Starting sample file:  Wed 8/29 
// the thread library is -lpthread
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUMT 8

// void function with 1 void paramater
//then you must type cast in the funciton
void *sayhi ( void* param  ){
	//convert the void and type casting it to be a long and assigning it to a long
	long myid = (long) param;
	long val;
	long sum = 1;
	
	val = myid % 2;		

	if(val == 1){
		for(int i = 1; i <= myid; i++){
				sum = sum * i;
		}
	}

	else if(val == 0){
		sum = 0;
		for(int i = 1; i <= myid; i++){
                                sum = sum + i;
                }
	}

	//exits the pthread library
	//returns a value back
	pthread_exit((void*) sum);
}


int main()
{
	//define thread array
	pthread_t tid[NUMT];
	void *status;
	long i;
	long total=0;

	for(i = 1; i <= NUMT; i++ )
	{
	//pass by reference is the &
	//first param  is the reference where to store the thread id
	//third the function to call when thread is created
	//fourth is the paramater being passed to the sayhi function
	//give the thread a unique id then do work in the funciton sayhi
	//must type cast the parameter
	pthread_create( &tid[i], NULL, sayhi, (void *)i );
	}


	for(i = 1; i <= NUMT; i++)
	{
	total += (void *)status;
	//this function waits to get a signal from the other thread and then joins them
	//kind of like the wait funciton.1
	pthread_join( tid[i], &status );
	printf("Hi, I'm thread %d and my value is %ld\n", i, (long)status);
	}

	printf("Total: %ld\n", total);
	return 0;
}


