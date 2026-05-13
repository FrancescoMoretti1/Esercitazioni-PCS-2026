#include <iostream>
#include "graph.hpp"

int main() {
    unidirected_graph g1;
    
    std::cout << "Test Inserimento e Verifica Nodi/Archi\n";
    g1.add_edge(1, 2);
    g1.add_edge(2, 3);
    g1.add_edge(3, 1); 
    g1.add_edge(4, 5); 

    std::cout << "Nodi in G1: ";
    for (int n : g1.all_nodes()) std::cout << n << " ";
    
    std::cout << "\nArchi in G1: ";
    for (auto e : g1.all_edges()) std::cout << e << " ";
    std::cout << "\n\n";

    std::cout << "--- Test Lista Vicini (Neighbours) ---\n";
    std::cout << "Vicini del nodo 1: ";
    for (int n : g1.neighbours(1)) std::cout << n << " ";
    std::cout << "\n\n";

    std::cout << "--Test Numerazione Archi (edge_number e edge_at)--\n";
    unidirected_edge test_edge(3, 1); 
    int id = g1.edge_number(test_edge);
    std::cout << "Arco " << test_edge << " ha ID: " << id << "\n";
    std::cout << "Arco recuperato all'ID " << id << " e': " << g1.edge_at(id) << "\n\n";

    std::cout << "Test Operatore Differenza (G1 - G2) \n";
    unidirected_graph g2;
    g2.add_edge(1, 2);
    g2.add_edge(4, 5);

    unidirected_graph g3 = g1 - g2;
    
    std::cout << "Archi in G1: ";
    for (auto e : g1.all_edges()) std::cout << e << " ";
    std::cout << "\nArchi in G2: ";
    for (auto e : g2.all_edges()) std::cout << e << " ";
    std::cout << "\nRisultato G1 - G2: ";
    for (auto e : g3.all_edges()) std::cout << e << " ";
    std::cout << "\n";

    return 0;
}

