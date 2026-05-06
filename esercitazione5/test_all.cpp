#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "sorting.hpp"
#include "randfiller.h"

int main() {
    randfiller rf;
    for(int i = 0; i < 100; ++i) {
        std::vector<int> v(10 + (rand() % 91)); 
        rf.fill(v, -1000, 1000);
        
        auto v1 = v, v2 = v;
        merge_sort(v1);
        quicksort(v2);
        
        if (!is_sorted(v1) || !is_sorted(v2)) return EXIT_FAILURE;
    }

    std::vector<std::string> vs = {"curl", "romeniandeadlift", "bulgariansplitsquat", "noonso", "overheadpress"};
    auto vs1 = vs, vs2 = vs;
    merge_sort(vs1);
    quicksort(vs2);
    if (!is_sorted(vs1) || !is_sorted(vs2)) return EXIT_FAILURE;

    return EXIT_SUCCESS;
}
