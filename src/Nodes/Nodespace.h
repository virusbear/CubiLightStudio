//
// Created by Virusbear on 26.06.2022.
//

#ifndef CUBILIGHTSTUDIO_NODESPACE_H
#define CUBILIGHTSTUDIO_NODESPACE_H

#include "Graph.h"
#include "Node.h"
#include "Port.h"
#include "Link.h"

namespace CubiLight {
    class Nodespace {
    private:
        Graph<Node> graph;
    public:
        void Evaluate();
        void operator +=(Node& node);
        void operator -=(Node& node);

        Link *link(Port& start, Port& end);
        void operator -=(Link& link);
    };
}

#endif //CUBILIGHTSTUDIO_NODESPACE_H
