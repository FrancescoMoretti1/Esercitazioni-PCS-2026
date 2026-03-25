#include <iostream>

int main() {
    double ad[4] = {0.0, 1.1, 2.2, 3.3};
    float af[8] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
    int ai[3] = {0, 1, 2};

    int x = 1;
    float y = 1.1;

    std::cout << "--- Indirizzi Array ---" << std::endl;
    for(int i=0; i<4; i++) std::cout << "ad[" << i << "]: " << &ad[i] << std::endl;
    for(int i=0; i<8; i++) std::cout << "af[" << i << "]: " << &af[i] << std::endl;
    for(int i=0; i<3; i++) std::cout << "ai[" << i << "]: " << &ai[i] << std::endl;

    std::cout << "\n--- Indirizzi Scalari ---" << std::endl;
    std::cout << "Indirizzo x: " << &x << std::endl;
    std::cout << "Indirizzo y: " << &y << std::endl;

    (&y)[1] = 0; 

    std::cout << "\nValore di x dopo l'operazione: " << x << std::endl;

    return 0;
}
