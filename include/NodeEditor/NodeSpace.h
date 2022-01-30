//
// Created by Virusbear on 29.01.2022.
//

#ifndef CUBILIGHTSTUDIO_NODESPACE_H
#define CUBILIGHTSTUDIO_NODESPACE_H

#include <vector>
#include "Node.h"
#include "Link.h"

namespace CubiLight {
    class NodeSpace {
    public:
        NodeSpace() = default;
        ~NodeSpace();
        Node *AddNode(Type *type);
        void RemoveNode(Node *node);

        Link *AddLink(Port *start, Port *end);
        void RemoveLink(Link *link);

        std::vector<Node *> GetNodes() const { return m_nodes; }
        std::vector<Link *> GetLinks() const { return m_links; }

        //TODO: void Evaluate();
    private:
        std::vector<Node *> m_nodes;
        std::vector<Link *> m_links;
    };
}

#endif //CUBILIGHTSTUDIO_NODESPACE_H
