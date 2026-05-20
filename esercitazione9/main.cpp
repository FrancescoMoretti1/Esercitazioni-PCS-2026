#include <iostream>
#include "graph.hpp"
#include "adapters.hpp"
#include "visits.hpp"

void print_graph_edges(const unidirected_graph& g, const std::string& name) {
    std::cout << "Archi di " << name << ": ";
    for (auto e : g.all_edges()) std::cout << e << " ";
    std::cout << "\n";
}

int main() {
    unidirected_graph G;
    G.add_edge(1, 2); G.add_edge(1, 3);
    G.add_edge(2, 4); G.add_edge(3, 4);
    G.add_edge(4, 5);

    print_graph_edges(G, "Grafo Originale G");

    fifo<int> q;
    auto bfsG = graph_visit(G, 1, q);
    print_graph_edges(bfsG, "Albero BFS (Sorgente 1)");

    lifo<int> s;
    auto dfsG = graph_visit(G, 1, s);
    print_graph_edges(dfsG, "Albero DFS Iterativa (Sorgente 1)");

    auto rec_dfsG = recursive_dfs(G, 1);
    print_graph_edges(rec_dfsG, "Albero DFS Ricorsiva (Sorgente 1)");

    auto dist = dijkstra(G, 1);
    std::cout << "Distanze minime dal nodo 1 (Dijkstra):\n";
    for (auto const& [node, distance] : dist) {
        std::cout << "Nodo " << node << " -> Distanza: " << distance << "\n";
    }

    return 0;
}
