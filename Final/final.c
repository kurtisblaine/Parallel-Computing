#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *PrintResult(void* param){
    long thread = (long) param;
    printf("thread %d says hi\n",thread);
    pthread_exit(NULL);
}

int main(int  argc, char* argv[]){
    long max = atoi(argv[1]);
    pthread_t tid[max];
    long index;

    for(index=1; index<= max; index++)  pthread_create(&tid[index], NULL, PrintResult, (void*) index);

    for(index=1; index<=max; index++)
        pthread_join(tid[index], NULL);

    return 0;
}
