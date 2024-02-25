#include <iostream>
#include <chrono>
#include "workload.h"

int main(){
    long long x;
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    while(true) {
        std::cout << "Input x:" << std::endl;
        std::cin >> x;
        auto t1 = high_resolution_clock::now();
        long long total = sumprimes(x);
        auto t2 = high_resolution_clock::now();
        auto ms_int = duration_cast<milliseconds>(t2 - t1);
        std::cout << "result = " << total << ", time(ms) = " << ms_int.count() << std::endl;
    }

    return 0;
}