#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]) {
    // Controllo passaggio nome file
    if (argc < 2) {
        std::cerr << "Errore: specificare il nome del file!" << std::endl;
        return 1;
    }

    std::ifstream file(argv[1]); 

    // Controllo esistenza file
    if (!file.is_open()) {
        std::cerr << "Errore: impossibile aprire il file " << argv[1] << std::endl;
        return 1;
    }

    std::string citta;
    double t0, t6, t12, t18;

    
    while (file >> citta >> t0 >> t6 >> t12 >> t18) {
        double media = (t0 + t6 + t12 + t18) / 4.0;
        std::cout << citta << " " << media << std::endl;
    }

    file.close();
    return 0;
}
