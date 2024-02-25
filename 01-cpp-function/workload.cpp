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