#include <iostream>
#include <chrono>
#include <omp.h>

int main() {
    omp_set_num_threads(8); 

    auto start = std::chrono::steady_clock::now();

    volatile long long sum = 0;
    const long long N = 10000000000LL;

    
    #pragma omp parallel for reduction(+:sum)
    for (long long i = 0; i < 50*N; ++i) {
        sum += i;
    }

    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << diff.count() << std::endl;

    return 0;
}
