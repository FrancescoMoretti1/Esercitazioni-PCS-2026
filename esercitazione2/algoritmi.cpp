#include <iostream>
#include <cmath>
#include <algorithm>

int main() {
    static const int N = 10;
    double arr[N] = {1.2, 3.4, 5.6, 7.8, 9.0, 2.1, 4.3, 6.5, 8.7, 0.9};

    double min_val = arr[0];
    double max_val = arr[0];
    double somma = 0;

    for(int i=0; i<N; i++) {
        min_val = std::min(min_val, arr[i]);
        max_val = std::max(max_val, arr[i]);
        somma += arr[i];
    }

    double media = somma / N;

    double somma_scarti = 0;
    for(int i=0; i<N; i++) {
        somma_scarti += std::pow(arr[i] - media, 2);
    }
    double dev_std = std::sqrt(somma_scarti / N);

    std::cout << "Minimo: " << min_val << std::endl;
    std::cout << "Massimo: " << max_val << std::endl;
    std::cout << "Media: " << media << std::endl;
    std::cout << "Deviazione Standard: " << dev_std << std::endl;

    return 0;
}
