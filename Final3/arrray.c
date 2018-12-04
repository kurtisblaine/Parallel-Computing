#include < stdio.h >
#include < omp.h >
#define N 100
int main(void) { 
  float a[N], b[N], c[N];
  int i;

  for (i = 0; i < N; i++) {
    a[i] = i * 2.0;
    b[i] = i * 3.0;
  }

  #pragma omp parallel shared(a, b, c) private(i)
  { 
    #pragma omp for             
    for (i = 0; i < N; i++) {
      c[i] = a[i] + b[i];
      printf ("%f\n", c[10]);
    }
  }
  
int local_suma, local_sumb, local_sumc, sum; 
#pragma omp parallel private(local_suma, local_sumb, local_sumc) shared(sum) 
  { 
    local_sum =0; 
    
#pragma omp for schedule(static,1) 
    for (int i=0; i< n; i++) {
      local_suma += a[i]; 
    }
    
#pragma omp for schedule(static,1) 
    for (int i=0; i< n; i++) {
      local_sumb += b[i]; 
    }

#pragma omp for schedule(static,1) 
    for (int i=0; i< n; i++) {
      local_sumc += c[i]; 
    }


#pragma omp critical 
    sum = local_suma + local_sumb + local_sumc;
  } 
  printf("sum=%d should be %d\n", sum, N*(N-1)/2);
}
