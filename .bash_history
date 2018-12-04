nano t1.c
ls
gcc t1.c -lpthread
./a.out
nano t1.c
ls
gcc t1.c -lpthread
./a.out
clear
ls
nano t1.c
ls
gcc t1.c -lpthread
./a.out
clear
nano t1.c
ls
clear
gcc t1.c -lpthread
./a.out
gcc t1.c -lpthread
nano t1.c
gcc t1.c -lpthread
./.aout
./a.out
clea
gcc t1.c -lpthread
nano t1.c
gcc t1.c -lpthread
./a.out
nano t1.c
gcc t1.c -lpthread
./a.out
nano t1.c
gcc t1.c -lpthread
./a.out
clear
gcc t1.c -lpthread
nano t1.c
gcc t1.c -lpthread
nano t1.c
gcc t1.c -lpthread
nano t1.c
gcc t1.c -lpthread
./a.out
nano t1.c
gcc t1.c -lpthread
./a.out
clear
nano t1.c
gcc t1.c -lpthread
./a.out
nano t1.c
gcc t1.c -lpthread
nano t1.c
gcc t1.c -lpthread
./a.out
cleart
clear
gcc t1.c -lpthread
nano t1.c
gcc t1.c -lpthread
./a.out
clear
gcc t1.c -lpthread
nano t1.c
gcc t1.c -lpthread
./a.out
lear
nano t1.c
gcc t1.c -lpthread
./a.out
nano t1.c
gcc t1.c -lpthread
nano t1.c
gcc t1.c -lpthread
nano t1.c
gcc t1.c -lpthread
./a.out
nano t1.c
gcc t1.c -lpthread
./a.out
clear
gcc t1.c -lpthread
nano t1.c
gcc t1.c -lpthread
./a.out
nano t1.c
gcc t1.c -lpthread
./a.out
clear
nano t1.c
gcc t1.c -lpthread
./a.out
nano t1.c
clear
ls
cd W2
ls
cd A1
ls
./a.out
nano t1.c
gcc t1.c -lpthread
./a.out
nano t1.c
gcc t1.c -lpthread
./a.out
nano t1.c
gcc t1.c -lpthread
./a.out
nano t1.c
gcc t1.c -lpthread
./a.out
nano t1.c
gcc t1.c -lpthread
nano t1.c
gcc t1.c -lpthread
nano t1.c
gcc t1.c -lpthread
./a.out

nano t1.c
gcc t1.c -lpthread
nano t1.c
gcc t1.c -lpthread
./a.out
cd W2
ls
cd A1
ls
cp t1.c .
cp t1.c .ls
clear
ls
cd
ls
dir
ls
cd
ls
path
pwd
cd W1
ls
cd 
cd W1
cd 
cd W2
ls
cd A1
ls
cp t1.c . /home/f18/p853
ls
cd~
ls
cd ~
ls
nano t1.c
gcc t1.c
nano t1.c
gcc t1.c
nano t1.c
ls
gcc t1.c
gcc t1.c -plthread
gcc t1.c -lpthread
./a.out
gcc t1.c -lpthread
./a.out
nano t1.c
gcc t1.c -lpthread
clear
ls
nano t1.c
ls
cp /tmp/pLoop.c .
ls
nano pLoop.c 
ls
nano t1.c
gcc t1.c -lpthread
./a.out
cat t1.c
clear
ls
mkdir W3
mv pLoop.c W3
ls
cd W3
ls
nano pLoop.c 
ls
clear
rm a.out
ls
cp t1.c .
ls
cp t1.c t2.c
ls
nano t2.c
cat t2.c
ls
nano t1.c
clear
ls
nano t1.c
cat t1.c
ls
nano t2.c
rm t2.c
nano t2.c
ls
gcc t2.c -lpthread
./a.out
clear
ls
cat t1.c
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 13
//static pthread_barrier_t barr;
int tr=0;
int k=0;
int n=0;
int A[MAX] = {0};
int Asum[MAX] = {0};
int total=0;
int mi, ma, od, ev, global;
pthread_mutex_t lock;
int odd ( int A[] ){
int odd = 0;
for(int i = 0; i<n; i++)
if(A[i]%2 == 1);  odd; //pthread_exit((void*) odd);
}
int even ( int A[] ){
int even = 0;
for(int i = 0; i<n; i++)
if(A[i]%2 == 0); ++; return even; //pthread_exit((void*) even);
}
int max(int A[]){
int max = A[0];
for(int i=1;i<n;i++){
if(A[i] > max){
max = A[i];
}
return max;
}
int min(int A[]){
int min = A[0];
for(int i=1;i<n;i++){
if(A[i] < min){
min = A[i];
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
int sum, f, start, end;
f = param;
for(int j=f;j<n;j=j+tr){
A[j] = gen(f, j);
}
if(f == 0); (A); if(f == 2){
od = odd(A);
ev = even(A);
}
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
{ printf("Numb of elements, threads, and key\n");
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
//prints output}!
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
printf("\nGlobal Sum:  %d", global);
//end print outputprintf("\nGlobal Sum:  %d", global);!
}
clear
ls
nano t2.c
rm t2.c
ls
nano t2.c
gcc t2.c -lpthreads
./a.out
ls
nano t2.c
gcc t2.c -lpthreads
nano t2.c
ls
clear
gcc t2.c -lpthread
./a.out
clear
ls
nano t3.c
ls
nano t2.c
clear
ls
nano t2.c
gcc t2.c -lpthread
./a.out
ls
clear
gcc t2.c -lpthread
./a.out
clear
ls
clear
nano t2.c
clear
ls
rm t2.c
ls
nano t2.c
clear
gcc t2.c -lpthread
./a.out
clear
rm t2.c
nano t2.c
gcc t2.c -lpthread
./a.out
ls
rm a.out
ls
clear
ls
cd share0924/
ls
gcc reduce1.c -fopenmp -o reduce1
./reduce1
gcc reduce1ic.c -o reduce1ic
gcc reduce1ic.c -fopenmp -o reduce1ic
./reduce1ic
gcc reduce2.c -fopenmp -o reduce2
./reduce2
clear
ls
gcc reduce3.c -fopenmp -o reduce3
./reduce3
ls
gcc transpose.c -o transpose
./transpose
gcc transposepar.c -fopenmp -o transposepar
./transposepar
nano transposepar.c
gcc transposepar.c -fopenmp -o transposepar
./transposepar
time ./transposepar
xkwE
CLEAR
clear
ls
gcc transposeparred.c -fopenmp -o transposeparred
./transposeparred
nano transposeparred.c
gcc transposeparred.c -fopenmp -o transposeparred
./transposeparred
clear
./transposeparred
clear
time ./transposeparred
clear
ls
cp /tmp/share0924.tar
cp /tmp/share0924.tar .
ls
tar -xf share0924.tar 
ls
rm share0924.tar
ls
cd share0924/
ls
nano section.c
gcc section.c -o section
gcc section.c -fopenmp -o section
ls
./section
gcc sec1.c -fopenmp -o sec1
./sec1
gcc reduce0 -o reduce0
gcc reduce0.c -o reduce0
./reduce0
ls
clear
ls
cd MatMul
ls
nano mmseq.c
ls
cd ..
ls
cd MatMul/
ls
nano mmpthread.c
ls
cd .
ls
cd ,,
ls
cd ..
ls
cd BufSched/
ls
nano dynomp
lear
nano dynomp.c
nano icomp.c
cd ..
ls
cd MatMul/
ls
nano mmpthread.c
./mmpthread.c 4 5 6
./mmpthread 4 5 6
gcc mmpthread.c -lpthread -o mmpthread
./mmpthread 4 5 6
gcc mmpthread.c -lpthread -o mmpthread
./mmpthread 4 5 6
./mmpthread
./mmpthread 6 7 8
clear
./mmpthread 6 7 8
./mmpthread
nano mmpthread.c
./mmpthread
clear
ls
./mmseq
./mmseq 1 2 3
./mmseq 4 5 6
./mmseq 10 10 10
clear
nano mmseq.c
./mmseq 4 5 6
./mmpthread
ls
nano mmpthread.c
gcc mmpthread.c -lpthread -o mmpthread
time ./mmpthread
nano mmpthread.c
gcc mmpthread.c -lpthread -o mmpthread
time ./mmpthread
ls
clear
ls
nano mmseq.c
nano mmpthread.c
clear
nano mmseq.c
time ./mmseq
time ./mmseq 9 8 7
nano mmseq.c
time ./mmseq 9 8 7
time ./mmseq 50 50 50
nano mmseq.c
clear
cp /tmp/oct1.tar
cp /tmp/oct1.tar .
ls
tar -xf oct1.tar
ls
rm oct1.tar 
ls
cd BufSched/
ls
nano origbuffsched.c 
gcc origbuffsched.c -o origbuffsched
./origbuffsched
gcc origbuffsched.c -o origbuffsched
nano origbuffsched.c 
ls
gcc origbuffsched.c -o origbuffsched
nano origbuffsched.c 
gcc origbuffsched.c -o origbuffsched
./origbuffsched
clear
ls
cat readme 
cat readme
clear
ls
nano buffsched.c
gcc buffsched.c -lpthread -o buffsched
./buffsched
time ./buffsched
ls
nano dynomp.c
fg
nano opmbuf.c
gcc opmbuff.c -o opmbuff
gcc opmbuf.c -o opmbuf 
gcc opmbuf.c -fopenmp -o opmbuf 
ls
gcc dynomp.c -fopenmp -o dynomp
./dynomp
ls
cat ptbase
cat seq.c
ls
clear
ls
gcc seq.c -o seq
./seq
clear
ls
cp origbuffssched.c icomp.c
cp origbuffsched.c icomp.c
nano icomp.c
gcc icomp.c -fopenmp -o icomp
nano icomp.c
gcc icomp.c -fopenmp -o icomp
./icomp
clear
ls
cd ..
ls
mkdir MatMul
ls
cd MatMul
ls
nano mmseq.c
ls
gcc mmseq.c -o mmseq
./mmseq
nano mmseq.c
./mmseq 5 6 7
ls
nano mmpthread.c
ls
gcc mmseq.c -lpthread -o mmseq
./mmseq
./mmseq 5 6 7
ls
clear
ls
cd ..
ls
cd MatMul/
ls
gcc mmseq.c -lpthread -o mmseq
ls
./mmseq
./mmseq 4 6 7
ls
ls -a
ls -l -a
ls
clear
ls
cat mmseq.c
nano mmomp.c
ls
cat mmseq.c > mmomp.c
ls
nano mmomp.c
ls
cat mmpthread.c > mmomp.c
nano mmomp.c
gcc mmomp.c -fopenmp -o mmomp
nano mmomp.c
gcc mmomp.c -fopenmp -o mmomp
nano mmomp.c
gcc mmomp.c -fopenmp -o mmomp
nano mmomp.c
gcc mmomp.c -fopenmp -o mmomp
./mmomp
./mmomp 5 6 7
clear
nano mmomp.c
gcc mmomp.c -fopenmp -o mmomp
./mmomp 5 6 7
./mmomp
nano mmomp.c
gcc mmomp.c -fopenmp -o mmomp
./mmomp
gcc mmomp.c -fopenmp -o mmomp
./mmomp
nano mmomp.c
gcc mmomp.c -fopenmp -o mmomp
./mmomp
clear
ls
nano mmomp.c
gcc mmomp.c -fopenmp -o mmomp
./mmomp
clear
time ./mmomp
ls
clear
nano mmomp.c
time ./mmomp
gcc mmomp.c -fopenmp -o mmomp
time ./mmomp
nano mmomp.c

time ./mmomp
nano mmomp.c
gcc mmomp.c -fopenmp -o mmomp
nano mmomp.c
gcc mmomp.c -fopenmp -o mmomp
clear
gcc mmomp.c -fopenmp -o mmomp
nano mmomp.c
gcc mmomp.c -fopenmp -o mmomp
nano mmomp.c
gcc mmomp.c -fopenmp -o mmomp

gcc mmomp.c -fopenmp -o mmomp
nano mmomp.c
gcc mmomp.c -fopenmp -o mmomp
nano mmomp.c
gcc mmomp.c -fopenmp -o mmomp
time ./mmomp
nano mmomp.c
gcc mmomp.c -fopenmp -o mmomp
nano mmomp.c
gcc mmomp.c -fopenmp -o mmomp
nano mmomp.c
gcc mmomp.c -fopenmp -o mmomp
clear
gcc mmomp.c -fopenmp -o mmomp
nano mmomp.c
gcc mmomp.c -fopenmp -o mmomp
time ./mmomp
time ./mmomp 4 5 6
clear
ls
nano mmomp.c
gcc mmomp.c -fopenmp -o mmomp
nano mmomp.c
gcc mmomp.c -fopenmp -o mmomp
time ./mmomp 9 8 7
clear
time ./mmomp 50 50 50
time ./mmomp 100 100 100
time ./mmomp 200 200 200
ls
clear
time ./mmomp 100 100 100
nano mmomp.c
gcc mmomp.c -fopenmp -o mmomp
time ./mmomp 100 100 100
clear
nano mmomp.c
ls
nano mmomp.c
clear
ls
clear
ls
cat mmomp
clear
ls
cat mmomp.c
ls
cd MatMul/
ls
./mmomp 10 10 10
./mmomp 10 10 12
ls
nano mmomp.c
./mmomp 10 10 12
gcc mmomp.c -fopenmp -o mmomp
./mmomp 10 10 12
clear
ls
nano mmomp.c
gcc mmomp.c -fopenmp -o mmomp
./mmomp 10 10 12
./mmomp 12
nano mmomp.c
gcc mmomp.c -fopenmp -o mmomp
./mmomp 12
./mmomp 12 12 12
nano mmomp.c
gcc mmomp.c -fopenmp -o mmomp
./mmomp 12 12 12
clear
nano mmomp.c
gcc mmomp.c -fopenmp -o mmomp
./mmomp 12 12 12
./mmomp 1
clear
ls
cat mmomp.c
cp /tmp/w0.c .
ls
nano w0.c
clear
gcc w0.c
ls
gcc w0.c -o w0
ls
rm a.out
ls
./w0
ls
./w0 5
./w0 10
./w0 8
./w0 11
clear
./w0 10101010102
time ./w0 1010101
time ./w0 101010010
nano w0.c
ls
nano w0.c
gcc w0.c -lm -o w0
nano w0.c
gcc w0.c -lm -o w0
./w0 0
ls
clear
ls
nano w0.c
gcc w0.c -lm -o w0
./w0 10
nano w0.c
./w0 1000
nano w0.c
./w0 1000
nano w0.c
gcc w0.c -lm -o w0
./w0 1000
clear
nano w0.c
gcc w0.c -lm -o w0
./w0 1000
gcc w0.c -lm -o w0
nano w0.c
gcc w0.c -lm -o w0
./w0 1000
./w0 10
clear
ls
cp w0.c w1.c
ls
nano w1.c
gcc w1.c -lm -o w1
nano w1.c
gcc w1.c -lm -o w1
./w1 10
clear
ls
cp /tmp/protomain.c .
cp /tmp/hashfun.o .
ls
gcc protomain.c hashfun.o -o hash
./hash
ls
./hash 1234
cat protomain.c
cat hashfun.o
clear

clear
./hash abc
./hash 123
./hash abc
./hash tyd
./hash kur
./hash 193485963
./hash
./hash 193485963
./hash
ls
clear
cp /temp/hashfun.c .
./hash
ls
gcc protomain.c hashfun.o
rm hash
ls
./a.out
./a.out 193485963
./a.out abc
ls
cd Hash/
ls
gcc hash.c -o hashfun.o
gcc hash.c hashfun.o
gcc hash.c -o hashfun.o
gcc hash.c hashfun.o
gcc hash.c hashfun.o -o go
ls
cd ,,
cd ..
ls
cd Hash
ls
ls -a
ls -l -a
ls
clear
ls
cp /tmp/hashfun.o .
ls
gcc hash.c hashfun.o
ls
./a.out 6385036879
ls
nano protomain.c
nano hash.c
ls
nano new.c
gcc new.c
nano new.c
gcc new.c
./a.out
clear
nano new.c
gcc new.c
./a.out
clear
ls
nano old.c
gcc old.c
nano old.c
ls
gcc old.c
./.aout
./a.out
nano old.c
clear
gcc old.c
./a.out
clear
ls
nano old.c
gcc old.c
./a.out
clear
ls
nano old.c
gcc old.c
./a.out
ls
clear
./a.out > perm.txt
cat perm.txt
clear
ls
rm protomain.c 
ls
nano hash.c
gcc hash.c hashfun.o
./a.out
clear
./a.out
clear
ls
hash.c hashfun.o -o hash
ls
gcc old.c -o generateData
ls
hash.c hashfun.o < perm.txt
./a.out < perm.txt
clear
ls
nano hash.c
ls
gcc hash.c hashfun.o
nano hash.c
gcc hash.c hashfun.o
./a.out < perm.txt
clear
ls
nano hash.c
ls
nano old.c
nano hash.c
./a.out < perm.txt
clear
ls
nano old.c
ls
nano hash.c
ls
mkdir Hash
ls
cd Hash
ls
nano hash.c
ls
cd ..
la
ls
mv protomain.c hashfun.o Hash
ls
cd Hash
ls
cd Hash
ls
rm generateData 
ls
nano hashomp.c
ls
gcc hashomp.c hashfun.o -fopenmp
ls
./a.out
./a.out 193514003
ls
mkdir test
mv new.c old.c perm.txt test
ls
mv hash.c hashseq.c
ls
gcc hashomp.c hashfun.o -o seq
gcc hashomp.c hashfun.o -o omp
ls
rm seq
rm a.out
ls
gcc hashseq.c hashfun.o -o seq
ls
./seq 193514003
clear
./seq 193514003
clear
ls
clear
ls
nano hashseq.c
gcc hashseq.c hashfun.o -o seq
./seq 193514003 
./seq 19351
nano hashseq.c
gcc hashseq.c hashfun.o -o seq
./seq 193514003
nano hashseq.c
gcc hashseq.c hashfun.o -o seq
./seq 193514003
./omp 193514003

gcc hashseq.c hashfun.o -o seq
nano hashseq.c
gcc hashseq.c hashfun.o -o seq
./seq 193514003
nano hashseq.c
gcc hashseq.c hashfun.o -o seq
./seq 193514003
nano hashseq.c
gcc hashseq.c hashfun.o -o seq
./seq 193514003
gcc hashseq.c hashfun.o -o seq
clear
ls
nano hashomp.c
nano hashseq.c
clear
ls
clear
nano hashseq.c
gcc hashseq.c hashfun.o -o seq
./seq 193485963
./seq 6385934658
./seq 193487502
./seq 193512196
time ./seq 193512196
ls clear
clear
ls
clear
ls'
clear
clear
ls
time ./omp 193514003
time ./omp 193512196
ls
nano hashomp.c
gcc hashomp.c hashfun.o -o omp
time ./omp 193487502
time ./omp 193485963
time ./omp 193514003
clear
ls
nano hashomp.c
pwd
ls
cd Hash
ls
nano hashomp.c
ls
gcc hashomp.c hashfun.o -o omp
time ./omp 193514003
nano hashomp.c
gcc hashomp.c hashfun.o -o omp
time ./omp 193514003
gcc hashomp.c hashfun.o -fopenmp -o omp
time ./omp 193514003
nano hashomp.c
gcc hashomp.c hashfun.o -fopenmp -o omp
time ./omp 193514003
gcc hashomp.c hashfun.o -fopenmp -o omp
time ./omp 193514003
nano hashomp.c
gcc hashomp.c hashfun.o -fopenmp -o omp
time ./omp 193514003
time ./omp 193512196
time ./omp 193487502
CLEAR
clear
time ./omp 193498380
time ./omp 193507093
cp /tmp/onesendrec.c .
ls
cp /tmp/410/onesendrec.c .
ls
mkdir MPI
ls
mv onesendrec.c MPI
ls
cat w0.c
ls
cat w1.c
ls
mkdir PrimeStuff
mv w0 w0.c w1 w1.c PrimeStuff
ls
rm a.out
ls
cd MPI
ls
clear
ls
mpicc onesendrec.c 
mpirun -np 2 ./a.out
mpicc onesendrec.c -o run
mpirun -np 2 ./run
cp onesendrec.c onea.c
ls
nano onea.c
mpi onea.c
mpicc onea.c
mpirun -np 2 a.out
nano onea.c
ls
cp onea.c oneb.c
ls
nano oneb.c
mpicc oneb.c -o b
mpirun -np 2 b
cp onea.c oneb2.c
nano oneb2.c
ls
rm oneb2.c
ls
clear
ls
cp /tmp/410/oneb.c .
ls
cp oneb.c onec.c
nano onec.c
mpicc onec.c
mpicc onec.c -o c
mpirun -np 2 c
cp /tmp/410/ring18.c . 
ls
mkdir Ring
mv ring18.c Ring
ls
cd Ring
ls
nano ring18.c 
mpicc ring18.c 
nano ring18.c 
mpicc ring18.c 
nano ring18.c 
mpicc ring18.c 
nano ring18.c 
mpicc ring18.c 
mpirun -np 4 ./a.out
clear
nano ring18.c 
mpicc ring18.c 
mpirun -np 4 ./a.out
clear
mpicc ring18.c 
nano ring18.c 
mpicc ring18.c
nano ring18.c 
mpicc ring18.c
nano ring18.c 
mpicc ring18.c
nano ring18.c 
mpicc ring18.c
mpirun -np 4 ./a.out
nano ring18.c 
mpicc ring18.c
mpirun -np 7 a.out
mpirun -np 1 a.out
cp ring18.c ring2.c
ls
nano ring2.c
mpicc ring2.c
nano ring2.c
mpicc ring2.c
mpicc ring2.c -o ring2
mpirun -np 10 ring2
nano ring2.c
mpirun -np 10 ring2
mpicc ring2.c -o ring2
mpirun -np 10 ring2
clear
mpirun -np 10 ring2
nano ring2.c
ls
nano ring18.c
nano ring2.c
mpicc ring2.c
mpirun -np 10 ./a.out
mpirun -np 13 ./a.out
mpirun -np 55 ./a.out
ls
cd Ring
ls
nano ring2.c
cp /tmp/410/ic1029.tar
cp /tmp/410/ic1029.tar .
tar -xf ic1029.tar
ls
rm ic1029.tar 
ls
mkdir MPI
ls
mv IC1029 MPI
ls
cd MPI
ls
cd IC1029/
ls
ls
cd MPI
ls
cd IC1029/
ls
nano scatter2.c
mpirun scatter2.c
nano scatter2.c
mpicc scatter2.c
nano scatter2.c
mpicc scatter2.c
nano scatter2.c
mpicc scatter2.c
mpirun -np 4 a.out
ls
cd ..
ls
cd ..
ls
cd Ring
ls
nano ring2.c
cp /tmp/410/pumpkin.c .
ls
mv pumpkin.c Ring
ls
cd Ring
ls
mv pumpkin.c .
mv pumpkin.c ..
ls
cd ..
ls
mv pumpkin.c MPI
ls
cd M
cd MPI
ls
nano pumpkin.c
vim pumpkin.c
ls
vim pumpkin.c
mpicc pumpkin.c
vim pumpkin.c
ls
vim punkin.c
ls
rm punkin.c 
ls
vim pumpkin.c
vim -r pumpkin.c
ls
ls 0a
ls -a
rm .pumpkin.c.swp 
ls
ls -a
vim pumpkin.c
mpicc pumpin.c
mpicc pumpkin.c
vim pumpkin.c
mpicc pumpkin.c
vim pumpkin.c
mpicc pumpkin.c
vim pumpkin.c
mpicc pumpkin.c
vim pumpkin.c
mpicc pumpkin.c
clear
mpicc pumpkin.c
vim pumpkin.c
mpicc pumpkin.c

mpicc pumpkin.c
vim pumpkin.c
mpicc pumpkin.c
vim pumpkin.c
mpicc pumpkin.c
mpirun -np 4 a.out
vim pumpkin.c
mpicc pumpkin.c
mpirun -np 4 a.out
vim pumpkin.c
mpirun -np 4 a.out
mpicc pumpkin.c
mpirun -np 4 a.out
vim pumpkin.c
mpicc pumpkin.c
vim pumpkin.c
mpicc pumpkin.c
mpirun -np 8 a.out
mpirun -np 5 a.out
vim pumpkin.c
clear
ls
mkdir MPI1
ls
cd MPI1
ls
vim ringlap.c
ls
cd ...
cd ..
ls
cd MPI
ls
cp pumpkin.c .. .
cp pumpkin.c .
cp pumpkin.c ringlap.c
ls
mv ringlap.c ..
ls
cd ..
ls
mv ringlap.c MPI1
ls
cd MPI1
ls
cp ringlap.c lister.c
ls
vim ringlap.c
ls
pwd
ls
cd MPI1
ls
vim ringlap.c
ls
vim ringlap.c
ls
mpicc ringlap.c -o ring
mpicc ringlap.c -o ringls
vim ringlap.c
ls
mpicc ringlap.c -o ringls
mpirun -np 4 ring 0
ls
mpicc ringlap.c -o ring
ls
rm ringls
ls
mpirun -np 4 ring 0
vim ringlap.c
ls
mpicc ringlap.c -o ring
vim ringlap.c
ls
mpicc ringlap.c -o ring
mpirun -np 4 ring 0 3
vim ringlap.c
ls
mpicc ringlap.c -o ring
mpirun -np 4 ring 0 3
vim ringlap.c
ls
mpicc ringlap.c -o ring
mpirun -np 4 ring 0 3
mpicc ringlap.c -o ring
mpirun -np 4 ring 0 3
vim ringlap.c
mpicc ringlap.c -o ring
mpirun -np 4 ring 0 3
clear
mpirun -np 4 ring 0 3
mpicc ringlap.c -o ring
vim ringlap.c
ls
mpirun -np 4 ring 0 3
clear
mpicc ringlap.c -o ring
mpirun -np 4 ring 1 4
mpicc ringlap.c -o ring
mpirun -np 4 ring 0 4
clear
ls
cd ..
ls
cd Ring
ls
vim ring_size.c
ls
cd ..
ls
cd MPI1
ls
rm ringlap.c
ls
vim ringlap.c
ls
ls -a
ls -l
ls -la
ls
clear
ls
vim ringlap.c
mpicc ringlap.c -o ring
vim ringlap.c
ls
mpicc ringlap.c -o ring
mpirun -np 4 ring 0 4
vim ringlap.c
mpicc ringlap.c -o ring
mpirun -np 4 ring 0 4
vim ringlap.c
mpicc ringlap.c -o ring
mpirun -np 4 ring 0 4
mpirun -np 4 ring 0 3
vim ringlap.c
mpicc ringlap.c -o ring
mpirun -np 4 ring 0 3
vim ringlap.c
mpicc ringlap.c -o ring
mpirun -np 4 ring 0 3
vim ringlap.c
mpirun -np 10 ring 0
mpirun -np 4 ring 0
mpirun -np 10 ring 0
mpirun -np 4 ring 0 4
mpirun -np 10 ring 2
mpirun -np 10 ring 5
clear
mpirun -np 10 ring 5
clear
vim ringlap.c
mpirun -np 10 ring 0 2
mpicc ringlap.c -o ring
mpirun -np 10 ring 0 2
clear
vim ringlap.c
ls
mpicc ringlap.c -o ring
mpirun -np 10 ring 0 2
vim ringlap.c
ls
vim lister.c
ls
mpicc lister.c -o ring
mpirun -np 10 ring 2
vim lister.c
mpicc lister.c -o ring
mpirun -np 10 ring 2
vim lister.c
mpicc lister.c -o ring
mpirun -np 10 ring 2
vim lister.c
ls

vim lister.c
mpicc lister.c -o ring
mpirun -np 10 ring 2
vim lister.c
mpicc lister.c -o ring
mpirun -np 10 ring 2
vim lister.c
mpicc lister.c -o ring
mpirun -np 10 ring 2
mpirun -np 10 ring 5
vim lister.c
mpicc lister.c -o ring
mpirun -np 10 ring 5
ls
clear
ls
rm ringlap.c
cp lister.c ringlap.c
ls
rm lister.c
ls
rm ring
mpicc ringlap.c -o ring
mpirun -np 10 ring 5
ls
vim ringlap.c
cat ringlap.c
ls
vim ringlap.c
ls
vim ringlap.c
ls
clear
ls
mpirun -np 15 ring 10
ls
clear
mpirun -np 2 ring 9
mpirun -np 5 ring 10
mpirun -np 15 ring 1
clear
ls
cd MPI!
cd MPI1
ls
vim ringlap.c
mpicc ringlap.c -o ring
mpirun -np 4 ring
vim ringlap.c
mpicc ringlap.c -o ring
mpirun -np 4 ring
clear
mpicc ringlap.c -o ring
ls
mpirun -np 10 ring
clear
ls
vim ringlap.c
ls
mpicc ringlap.c -o ring
vim ringlap.c

vim ringlap.c
mpicc ringlap.c -o ring
mpirun -np 10 ring
clear
vim ringlap.c
mpicc ringlap.c -o ring
mpirun -np 10 ring 0
vim ringlap.c
mpicc ringlap.c -o ring
mpirun -np 10 ring 0
mpirun -np 10 ring
clear
mpirun -np 10 ring 10
mpirun -np 15 ring
clear
mpirun -np 9 ring
clear
mpirun -np 5 ring
mpirun -np 5 ring 0
mpirun -np 10 ring 0
mpirun -np 5 ring 10
clear
vim ringlap.c
mpirun -np 10 ring 0
mpicc ringlap.c -o ring
mpirun -np 10 ring 0
vim ringlap.c
mpicc ringlap.c -o ring
mpirun -np 10 ring 0
vim ringlap.c
mpicc ringlap.c -o ring
mpirun -np 10 ring 0
mpirun -np 8 ring 0
mpirun -np 2 ring 0
mpirun -np 3 ring 0
mpirun -np 8 ring 0
clear
vim ringlap.c
mpicc ringlap.c -o ring
mpirun -np 8 ring 0
mpicc ringlap.c -o ring
mpirun -np 8 ring 1
mpirun -np 8 ring 3
vim ringlap.c
mpicc ringlap.c -o ring
mpirun -np 8 ring 3
clear
vim ringlap.c
ls
mpicc ringlap.c -o ring
mpirun -np 8 ring 3
mpirun -np 8 ring 5
clear
mpicc ringlap.c -o ring
vim ringlap.c
mpicc ringlap.c -o ring
mpirun -np 8 ring 5
vim ringlap.c
mpicc ringlap.c -o ring
mpirun -np 8 ring 5
vim ringlap.c
ls
mpirun -np 8 ring 6
clear
ls
cp ringlap.c lister.c
ls
vim lister.c
ls
clear
ls
clear
ls
clear
lsljlj
ls
clear
cp /tmp/410/pumpkinGood.c .
ls
mv pumpkinGood.c MPI
ls
cd MPI
ls
vim pumpkinGood.c
ls
cp pumpkinGood.c pumpkinreduce.c
ls
clear
ls
cd ..
ls
cd MPI1
ls
vim lister.c
ls
rm lister.c
vim lister.c
ls
vim ringlap.c
vim lister.c
ls
vim lister.c
mpicc lister.c -o list
mpirun -np 3 list
vim lister.c
ls
cd MPI1
ls
mpirun -np 8 list
clear
ls
clear
ls
rm lister.c list
vim lister.c
ls
ls -a
rm .lister.c.swp 
ls
clera
ls
vim lister.c
ls
vim ringlap.c
l
ls
vim lister.c
ls
mpicc lister.c -o list
vim lister.c
mpicc lister.c -o list
vim lister.c
ls
mpicc lister.c -o list
mpirun -np 3 ./list
mpirun -np 10 ./list
vim lister.c
mpicc lister.c -o list
mpirun -np 10 ./list
vim lister.c
mpicc lister.c -o list
mpirun -np 10 ./list
vim lister.c
mpicc lister.c -o list
mpirun -np 10 ./list
vim lister.c
mpicc lister.c -o list
mpirun -np 10 ./list
vim lister.c

vim lister.c
mpicc lister.c -o list
mpirun -np 10 ./list
vim lister.c
mpic
vim lister.c
mpicc lister.c -o list

vim lister.c
mpicc lister.c -o list
vim lister.c
mpicc lister.c -o list
mpirun -np 10 ./list
vim lister.c
mpicc lister.c -o list
mpirun -np 10 ./list
vim lister.c
mpicc lister.c -o list
mpirun -np 10 ./list
vim lister.c
mpicc lister.c -o list
mpirun -np 10 ./list
vim lister.c
mpicc lister.c -o list
mpirun -np 10 ./list
mpirun -np 5 ./list
ls
vim test.c
mpicc test.c 
ls
mpirun -np 10 a.out
ls
clear
ls
rm test.c a.out
ls
vim test.c
ls
ls -a
vim lister.c
mpicc lister.c -o list
mpirun -np 10 ./list
vim lister.c
mpicc lister.c
vim lister.c
mpicc lister.c -o list
mpirun -np 10 ./list
vim lister.c
mpicc lister.c -o list
mpirun -np 10 ./list
vim lister.c
mpicc lister.c -o list
vim lister.c
mpicc lister.c -o list
mpirun -np 10 ./list
vim lister.c
mpicc lister.c -o list
mpirun -np 10 ./list
clear
mpirun -np 10 ./list
mpirun -np 3 ./list
vim lister.c
mpicc lister.c -o list
mpirun -np 3 ./list
mpirun -np 10 ./list
vim lister.c
mpirun -np 3 ./list
mpirun -np 10 ./list
mpicc lister.c -o list
mpirun -np 10 ./list
vim lister.c
mpicc lister.c -o list
mpirun -np 10 ./list
vim lister.c
mpicc lister.c -o list
vim lister.c
mpicc lister.c -o list
vim lister.c
mpicc lister.c -o list
mpirun -np 10 ./list
vim lister.c
mpicc lister.c -o list
mpirun -np 10 ./list
clear
mpirun -np 10 ./list
mpicc lister.c -o list
vim lister.c
mpicc lister.c -o list
mpirun -np 10 ./list
vim lister.c
mpicc lister.c -o list
mpirun -np 10 ./list
vim lister.c
mpicc lister.c -o list
mpirun -np 10 ./list
vim lister.c
mpicc lister.c -o list
mpirun -np 10 ./list
vim lister.c
clear
ls
vim listers.c
clear
mpicc listers.c
vim listers.c
mpicc listers.c
vim listers.c
mpicc listers.c
mpirun -np 10 a.out
mpicc listers.c
vim listers.c
mpicc listers.c
mpirun -np 10 a.out
mpicc listers.c
vim listers.c
mpicc listers.c
mpirun -np 10 a.out
mpicc listers.c
vim listers.c
mpicc listers.c
vim listers.c
mpicc listers.c
mpirun -np 10 a.out
clear
vim listers.c
mpicc listers.c
mpirun -np 10 a.out
vim listers.c
mpicc listers.c
mpirun -np 5 a.out
vim listers.c
mpicc listers.c
mpirun -np 5 a.out
mpicc listers.c
vim listers.c
mpicc listers.c
mpirun -np 5 a.out
mpicc listers.c
vim listers.c
mpicc listers.c
vim listers.c
mpicc listers.c
mpirun -np 5 a.out
vim listers.c
mpicc listers.c
mpirun -np 5 a.out
clear
ls
rm lister.c
ls
rm list
ls
mpirun -np 5 a.out

vim listers.c
mpicc listers.c

mpirun -np 10 a.out
ls
cat lister.c
cat listers.c
ls
clear
ls
clear
cd ..
ls
clear
ls
mkdir Final
ls
cd Final
ls
vim final.c
cat final.c
ls
gcc -lpthread final.c
vim final.c
gcc -lpthread final.c
vim final.c
gcc -lpthread final.c
vim final.c
gcc -lpthread final.c
vim final.c
gcc -lpthread final.c
ls
./a.out
clear
./a.out 10
./a.out 20
vim final.c
gcc -lpthread final.c
./a.out 20 > output20.txt
./a.out 30 > output30.txt
cat output20.txt 
cat output30.txt
./a.out 10 > output10.txt
ls
clear
ls
clear
ls
cd Final
ls
pwd
ls
mkdir Final2
ls
cd Final2
ls
vim ParSearch.c
gcc -o ParSearch -fopenmp ParSearch.c
vim ParSearch.c 
gcc -o ParSearch -fopenmp ParSearch.c
./ParSearch 
vim ParSearch.c 
gcc -o ParSearch -fopenmp ParSearch.c
vim ParSearch.c 
ls
gcc -o ParSearch -fopenmp ParSearch.c
vim ParSearch.c 
gcc -o ParSearch -fopenmp ParSearch.c
vim ParSearch.c 
gcc -o ParSearch -fopenmp ParSearch.c
vim ParSearch.c 
gcc -o ParSearch -fopenmp ParSearch.c
vim ParSearch.c 
gcc -o ParSearch -fopenmp ParSearch.c
./ParSearch 
vim ParSearch.c 
gcc -o ParSearch -fopenmp ParSearch.c
./ParSearch 
vim ParSearch.c 
gcc -o ParSearch -fopenmp ParSearch.c
./ParSearch 
gcc -o ParSearch -fopenmp ParSearch.c
vim ParSearch.c 
gcc -o ParSearch -fopenmp ParSearch.c
./ParSearch 
vim ParSearch.c 
gcc -o ParSearch -fopenmp ParSearch.c
./ParSearch 
ls
pwd
cat ParSearch
clear
ls
cat ParSearch.c
ls
cd MPI
ls
./b
./b 4
ls
clear
ls
vim pumpkinGood.c
ls
mpirun -np 4 run
mpirun -np 4 b
clear
ls
clear
cd ..
ls
cd MPI1
ls
mpirun -np 10 ring
clear
ls
mpicc ringlap.c -o ring
ls
mpirun -np 10 ring
clear
mpicc ringlap.c -o ring
mpirun -np 10 ring 3
vim ringlap.c
ls
mpirun listers.c -o list
mpicc lister.c -o list
mpicc listers.c -o lists
mpirun -np 10 lists
cd ..
ls
cd Final2
ls
vim turnip.c
mpicc turnip.c -o turnip
vim turnip.c
mpicc turnip.c -o turnip
clear
mpicc turnip.c -o turnip
vim turnip.c
mpicc turnip.c -o turnip
vim turnip.c
mpicc turnip.c -o turnip
clear
mpicc turnip.c -o turnip
vim turnip.c
mpicc turnip.c -o turnip
vim turnip.c
mpicc turnip.c -o turnip
vim turnip.c
mpicc turnip.c -o turnip
ls
mpirun -np 10 turnip
mpirun turnip
mpirun -np 15 turnip
vim turnip.c
mpirun -np 15 turnip
mpicc turnip.c -o turnip
mpirun -np 15 turnip
vim turnip.c
mpicc turnip.c -o turnip
vim turnip.c
mpicc turnip.c -o turnip
mpirun -np 15 turnip
vim turnip.c
mpicc turnip.c -o turnip
mpirun -np 15 turnip
mpirun turnip
vim turnip.c
mpirun -np 15 turnip
mpicc turnip.c -o turnip
mpirun turnip
vim turnip.c
mpicc turnip.c -o turnip
mpirun turnip
vim turnip.c
mpicc turnip.c -o turnip
mpirun turnip
mpirun turnip 1
mpirun turnip 1 2
mpirun 1 2 turnip
mpirun -np 10 turnip
vim turnip.c
mpicc turnip.c -o turnip
mpirun -np 10 turnip
vim turnip.c
mpicc turnip.c -o turnip
mpirun -np 10 turnip
vim turnip.c
mpicc turnip.c -o turnip
mpirun -np 10 turnip
vim turnip.c
mpicc turnip.c -o turnip
mpirun -np 10 turnip
vim turnip.c
mpicc turnip.c -o turnip
mpirun -np 10 turnip
vim turnip.c
mpicc turnip.c -o turnip
mpirun -np 10 turnip
ls
clear
ls
cat turnip.c
ls
cd Final2
ls
cat turnip.c
