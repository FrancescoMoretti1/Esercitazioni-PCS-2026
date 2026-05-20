#ifndef VISITS_HPP
#define VISITS_HPP

#include "graph.hpp"
#include <set>
#include <map>
#include <queue>
#include <vector>

template<typename Container>
unidirected_graph graph_visit(const unidirected_graph& G, int start_node, Container& c) {
    unidirected_graph tree;
    std::set<int> visited;
    std::map<int, int> parent; 
    
    c.put(start_node);
    visited.insert(start_node);

    while (!c.empty()) {
        int curr = c.get();
        
        if (curr != start_node && tree.all_nodes().find(curr) == tree.all_nodes().end()) {
             tree.add_edge(parent[curr], curr);
        }

        for (int neighbor : G.neighbours(curr)) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                parent[neighbor] = curr;
                c.put(neighbor);
            }
        }
    }
    return tree;
}

void dfs_recursive_helper(const unidirected_graph& G, int curr, std::set<int>& visited, unidirected_graph& tree) {
    visited.insert(curr);
    for (int neighbor : G.neighbours(curr)) {
        if (visited.find(neighbor) == visited.end()) {
            tree.add_edge(curr, neighbor);
            dfs_recursive_helper(G, neighbor, visited, tree);
        }
    }
}

unidirected_graph recursive_dfs(const unidirected_graph& G, int start_node) {
    unidirected_graph tree;
    std::set<int> visited;
    dfs_recursive_helper(G, start_node, visited, tree);
    return tree;
}

std::map<int, int> dijkstra(const unidirected_graph& G, int start_node) {
    std::map<int, int> distances;
    for (int n : G.all_nodes()) distances[n] = 1e9; 
    distances[start_node] = 0;

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    pq.push({0, start_node});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > distances[u]) continue;

        for (int v : G.neighbours(u)) {
            if (distances[u] + 1 < distances[v]) { 
                distances[v] = distances[u] + 1;
                pq.push({distances[v], v});
            }
        }
    }
    return distances;
}

#endif

