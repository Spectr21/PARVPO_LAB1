#include <iostream>
#include <chrono>
#include <thread>

int main() {
    auto start = std::chrono::steady_clock::now();
   
    volatile long long sum = 0;
    for (long long i = 0; i < 10000000000; ++i) { 
        sum += i; 
    }

    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << diff.count() << std::endl;
    return 0;
}
