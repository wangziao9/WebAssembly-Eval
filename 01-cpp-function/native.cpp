#include <iostream>
#include <chrono>
#include "workload.h"

int main(){
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    int myfunc;
    std::cout << "Choose workload: 1) sumprimes, 2) fibonacci, 3) matmul" << std::endl;
    std::cin >> myfunc;
    int x;

    while(true) {
        std::cout << "Input x:" << std::endl;
        std::cin >> x;
        auto t1 = high_resolution_clock::now();
        long long total = (myfunc == 1)? sumprimes(x): ((myfunc == 2)? fib(x): matmul(x));
        auto t2 = high_resolution_clock::now();
        auto ms_int = duration_cast<milliseconds>(t2 - t1);
        std::cout << "result = " << total << ", time(ms) = " << ms_int.count() << std::endl;
    }

    return 0;
}