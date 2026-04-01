#include <iostream>
#include "rational.hpp"

int main() {
    // Test richiesto 3/6
    rational<int> r(3, 6);
    std::cout << "Semplificazione 3/6: " << r << std::endl;

    // Test op
    rational<int> a(1, 2);
    rational<int> b(1, 4);
    std::cout << a << " + " << b << " = " << (a + b) << std::endl;

    rational<int> inf(1, 0); 
    std::cout << "Test Inf: " << inf << std::endl;
    std::cout << a << " + Inf = " << (a + inf) << std::endl;

    return 0;
}
