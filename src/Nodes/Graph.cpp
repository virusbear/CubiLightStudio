//
// Created by Virusbear on 25.06.2022.
//

#include "Graph.h"
#include <unordered_set>

namespace CubiLight {
    template <typename V>
    void Graph<V>::operator+=(V& vertex) {
        if(adjacency.find(&vertex) != adjacency.end()) return;

        adjacency.insert(std::pair(&vertex, std::set<V *>()));
    }

    template <typename V>
    void Graph<V>::operator-=(V& vertex) {
        adjacency -= &vertex;
        degree -= &vertex;

        for(auto pair : adjacency) {
            pair.second -= &vertex;
        }
    }

    template <typename V>
    void Graph<V>::link(V& start, V& end) {
        if(adjacency.find(&start) == adjacency.end()) return;
        if(adjacency.find(&end) == adjacency.end()) return;

        adjacency[&start] += &end;
        degree[&start]++;
        degree[&end]++;
    }

    template <typename V>
    void Graph<V>::unlink(V& start, V& end) {
        if(adjacency.find(&start) == adjacency.end()) return;
        if(adjacency.find(&end) == adjacency.end()) return;

        if(degree[&start] > 0) {
            degree[&start]--;
        }
        if(degree[&end] > 0) {
            degree[&end]--;
        }
    }

    template <typename V>
    std::vector<V *> Graph<V>::topologicalSort() {
        std::vector<V&> result;
        std::unordered_set<V *> visited;

        for(auto adj: adjacency) {
            if(visited.find(&(adj.first)) == visited.end()) {
                topologicalSort0(adjacency, adj.first, visited, result);
            }
        }

        return std::vector(result.end(), result.begin());
    }

    template <typename V>
    void topologicalSort0(std::unordered_map<V *, V *> adjacency, V *vertex, std::unordered_set<V *>& visited, std::vector<V&>& result) {
        visited += vertex;

        for(auto adj: adjacency[vertex]) {
            if(visited.find(adj) == visited.end()) {
                topologicalSort0(adjacency, adj, visited, result);
            }
        }

        result.push_back(vertex);
    }
}