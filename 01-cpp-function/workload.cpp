#include "workload.h"

bool isprime(long long x){
    if (x < 2) return false;
    for (long long i = 2; i*i <= x ; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

long long sumprimes(long long bound){
    long long total = 0;
    for (long long i = 1; i <= bound; i++){
        if (isprime(i)) {
            total += i;
        }
    }
    return total;
}

long long fib(int x){
    if (x <= 0) return 0;
    if (x == 1 || x == 2) return 1;
    return fib(x-1) + fib(x-2);
}

int lcg(int x){
    // Linear Congruential Generator
    int modulus = (1 << 15) + 1;
    int a = 75;
    int c = 74;
    return (a*x+c)%modulus;
}

int matmul(int n) {
    int seed = 1;
    // Instantiate matrices
    int *A = new int[n*n];
    int *B = new int[n*n];
    for(int i=0;i<n*n;i++) {
        A[i] = seed;
        seed = lcg(seed);
    }
    for(int i=0;i<n*n;i++) {
        B[i] = seed;
        seed = lcg(seed);
    }
    // Naive Matrix Multiplication
    int *R = new int[n*n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            R[i*n+j] = 0;
            for(int k=0;k<n;k++){
                R[i*n+j] += A[i*n+k]*B[k*n+j];
            }
        }
    }
    // Pool output
    int pool = 1;
    int modulus = (1 << 16) + 1;
    int a = 75;
    for(int i=0;i<n*n;i++){
        pool = (a*pool+R[i])%modulus;
    }
    delete [] A;
    delete [] B;
    delete [] R;
    return pool;
}