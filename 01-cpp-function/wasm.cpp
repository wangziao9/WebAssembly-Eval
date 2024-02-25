#include <iostream>
#include <chrono>
#include "workload.h"
#include <emscripten/emscripten.h>
using namespace std;


int main() {
    cout << "application started" << endl;
    return 0;
}

#ifdef __cplusplus
#define EXTERN extern "C"
#else
#define EXTERN
#endif

EXTERN EMSCRIPTEN_KEEPALIVE void runner(long long x) {
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;
    auto t1 = high_resolution_clock::now();
    long long total = sumprimes(x);
    auto t2 = high_resolution_clock::now();
    auto ms_int = duration_cast<milliseconds>(t2 - t1);
    std::cout << "input = " << x << " result = " << total << std::endl;
    std::cout << ms_int.count() << "ms\n";
}