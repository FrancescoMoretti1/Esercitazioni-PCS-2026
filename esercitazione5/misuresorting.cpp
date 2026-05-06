#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "sorting.hpp"
#include "randfiller.h"
#include "timecounter.h"

void benchmark(int N) {
    int num_vectors = 100;
    randfiller rf;
    timecounter tc;
    
    std::vector<std::vector<int>> matrix_orig(num_vectors, std::vector<int>(N));
    for (int i = 0; i < num_vectors; ++i) {
        rf.fill(matrix_orig[i], -10000, 10000);
    }

    std::cout << "N=" << std::left << std::setw(5) << N;

    auto matrix = matrix_orig;
    tc.tic();
    for(int i = 0; i < num_vectors; ++i) merge_sort(matrix[i]);
    std::cout << " | Merge: " << std::fixed << std::setprecision(6) << tc.toc() / num_vectors << "s";

    matrix = matrix_orig; tc.tic();
    for(int i = 0; i < num_vectors; ++i) quicksort(matrix[i]);
    std::cout << " | Quick: " << tc.toc() / num_vectors << "s";

    matrix = matrix_orig; tc.tic();
    for(int i = 0; i < num_vectors; ++i) hybrid_quicksort(matrix[i]);
    std::cout << " | Hybrid: " << tc.toc() / num_vectors << "s";

    matrix = matrix_orig; tc.tic();
    for(int i = 0; i < num_vectors; ++i) std::sort(matrix[i].begin(), matrix[i].end());
    std::cout << " | std::sort: " << tc.toc() / num_vectors << "s\n";
}

int main() {
    for (int n = 10; n <= 10000; n *= 2) benchmark(n);
    return 0;
}
