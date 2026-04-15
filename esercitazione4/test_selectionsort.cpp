#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "sorting.hpp"
#include "randfiller.h"

int main() {
    randfiller rf;
    // Test su 100 vettori casuali
    for(int i = 0; i < 100; ++i) {
        std::vector<int> v(10 + (rand() % 91)); 
        rf.fill(v, -1000, 1000); // Numeri negativi e positivi 
        selection_sort(v);
        if (!is_sorted(v)) return EXIT_FAILURE;
    }
    // Test su stringhe
    std::vector<std::string> vs = {"squat", "panca", "stacco", "jiujitsu", "repeat"};
    selection_sort(vs);
    if (!is_sorted(vs)) return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
