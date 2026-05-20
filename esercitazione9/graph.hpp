#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <stdexcept>

// Classe per l'arco
class unidirected_edge {
private:
    int u, v;
public:
    unidirected_edge(int a, int b) {
        u = std::min(a, b);
        v = std::max(a, b);
    }
    
    int from() const { return u; }
    int to() const { return v; }

    bool operator<(const unidirected_edge& other) const {
        if (u != other.u) return u < other.u;
        return v < other.v;
    }

    bool operator==(const unidirected_edge& other) const {
        return u == other.u && v == other.v;
    }

    friend std::ostream& operator<<(std::ostream& os, const unidirected_edge& e) {
        os << "{" << e.u << ", " << e.v << "}";
        return os;
    }
};

// Classe per il grafo
class unidirected_graph {
private:
    std::set<int> _nodes; 
    std::set<unidirected_edge> _edges; 
    std::unordered_map<int, std::list<int>> _adj; 
    std::map<unidirected_edge, int> _edge_to_id;
    std::map<int, unidirected_edge> _id_to_edge;
    int _next_edge_id;

public:
    unidirected_graph() : _next_edge_id(0) {}

    unidirected_graph(const unidirected_graph& other) = default;

    void add_edge(int u, int v) {
        unidirected_edge e(u, v);
        if (_edges.find(e) == _edges.end()) {
            _edges.insert(e);
            _nodes.insert(u);
            _nodes.insert(v);
            
            _adj[u].push_back(v);
            _adj[v].push_back(u);
            
            _edge_to_id[e] = _next_edge_id;
            _id_to_edge.insert({_next_edge_id, e});
            _next_edge_id++;
        }
    }

    std::list<int> neighbours(int u) const {
        auto it = _adj.find(u);
        if (it != _adj.end()) return it->second;
        return std::list<int>();
    }

    std::set<unidirected_edge> all_edges() const {
        return _edges;
    }

    std::set<int> all_nodes() const {
        return _nodes;
    }

    int edge_number(const unidirected_edge& e) const {
        auto it = _edge_to_id.find(e);
        if (it != _edge_to_id.end()) return it->second;
        throw std::invalid_argument("Arco non presente nel grafo");
    }

    unidirected_edge edge_at(int id) const {
        auto it = _id_to_edge.find(id);
        if (it != _id_to_edge.end()) return it->second;
        throw std::out_of_range("ID arco non valido");
    }

    unidirected_graph operator-(const unidirected_graph& other) const {
        unidirected_graph result;
        for (const auto& e : _edges) {
            if (other._edges.find(e) == other._edges.end()) {
                result.add_edge(e.from(), e.to());
            }
        }
        return result;
    }
};

#endif
