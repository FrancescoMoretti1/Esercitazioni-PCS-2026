#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "sorting.hpp"
#include "randfiller.h"
#include "timecounter.h"

void benchmark(int n) {
    randfiller rf;
    timecounter tc;
    std::vector<int> v(n);
    rf.fill(v, -10000, 10000);

    auto v1 = v, v2 = v, v3 = v, v4 = v;

    std::cout << "N=" << std::left << std::setw(5) << n;
    
    tc.tic(); bubble_sort(v1);
    std::cout << " | Bubble: " << std::fixed << std::setprecision(5) << tc.toc() << "s";
    
    tc.tic(); insertion_sort(v2);
    std::cout << " | Insert: " << tc.toc() << "s";
    
    tc.tic(); selection_sort(v3);
    std::cout << " | Select: " << tc.toc() << "s";
    
    tc.tic(); std::sort(v4.begin(), v4.end());
    std::cout << " | std::sort: " << tc.toc() << "s" << std::endl;
}

int main() {
    for (int n = 4; n <= 8192; n *= 2) {
        benchmark(n);
    }
    return 0;
}
