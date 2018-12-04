
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 13

int tr=0;
int k=0;
int n=0;
int A[MAX] = {0};
int Asum[MAX] = {0};
int total=0;
int mi, ma, od, ev, global;
pthread_mutex_t lock;
//pthread_barrier_t barr[MAX];



int odd ( int A[] ){
	int odd = 0;

	for(int i = 0; i<n; i++)
		if(A[i]%2 == 1)
			odd++;

	return odd;
}

int even ( int A[] ){
	int even = 0;

	for(int i = 0; i<n; i++)
		if(A[i]%2 == 0)
			even++;

	return even;
}

int max(int A[]){

	int max = A[0];

	for(int i=1;i<n;i++){
		if(A[i] > max){
			max = A[i];
		}
	}

	return max;
}

int min(int A[]){
	int min = A[0];

	for(int i=1;i<n;i++){
			if(A[i] < min){
				min = A[i];
			}
	}

	return min;

}

int gen(int t, int i ){
	//pthread_mutex_lock(&lock);
	i++;
	int v = (t * 13)%k + (i * 7)%k + (t * i * k)%k;
	return v;
	//pthread_mutex_unlock(&lock);
}

void *first(void* param){
pthread_mutex_lock (&lock);
	int sum, f, start, end;
	f = param;
	for(int j=f;j<n;j=j+tr){
			A[j] = gen(f, j);
	}
pthread_mutex_unlock (&lock);
//pthread_barrier_wait(&barr);
pthread_mutex_lock (&lock);
	if(f == 0)
		ma = max(A);

	if(f == 1)
		mi = min(A);

	if(f == 2){
		od = odd(A);
		ev = even(A);
	}
pthread_mutex_unlock (&lock);
//pthread_barrier_wait(&barr);

	sum = 0;

pthread_mutex_lock (&lock);
	start = n / tr * f;
	end = n / tr * (f + 1);
	if ( f == (tr - 1) ) end = n;

	for(int i = start; i < end; i++){
			sum += A[i];
	}

	Asum[f] = sum;

	global += sum;
pthread_mutex_unlock (&lock);

	pthread_exit(NULL);
}

int main()
{
	//pthread_barrierattr_t attr;
	//pthread_barrier_init(&barr, NULL, tr);

	printf("Numb of elements, threads, and key\n");
	scanf("%d", &n);
	scanf("%d", &tr);
	scanf("%d", &k);

	//defining...
	pthread_mutex_init(&lock, NULL);
	pthread_t tid[tr];

	for(int i=0; i< tr; i++){
		tid[i];
	}

	for(int i=0; i< tr; i++)
	pthread_create( &tid[i], NULL, first, (void *)i);

	for(int i=0; i < tr; i++){
		pthread_join( tid[i], NULL );
		//printf("im thread %d and answer is %ld\n", i, (long)status);
	}

	//prints output!!!
	printf("Using   N:%d     T:%d     key:%d\n", n, tr, k);
	printf("List:");
	for(int i=0;i<n;i++){
			printf("  %d", A[i]);
	}
	printf("\nStats:\n");
	printf("Max:%d  Min:%d  Odd:%d  Even:%d\n", ma,mi,od,ev);
	printf("Partial Sum:");
	for(int i=0; i<tr; i++){
		printf("   T%d: %d", i, Asum[i]);
	}
	printf("\nGlobal Sum:  %d\n", global);
	//end print output!!!

}

