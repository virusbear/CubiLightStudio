#pragma once

#include <unordered_map>
#include <set>
#include <vector>
#include "Node.h"

namespace CubiLight
{
    template <typename V>
    class Graph {
        private:
            std::unordered_map<V *, std::set<V *>> adjacency;
            std::unordered_map<V *, int> degree;
        public:
            int size() const { return adjacency.size(); };

            void operator +=(V& vertex);
            void operator -=(V& vertex);

            void link(V& start, V& end);
            void unlink(V& start, V& end);

            std::vector<V&> topologicalSort();
    };
}
