//
// Created by Virusbear on 29.01.2022.
//

#include "NodeTemp/NodeSpace.h"
#include "NodeTemp/NodeRegistry.h"
#include <algorithm>

namespace CubiLight {
    NodeSpace::~NodeSpace() {
        for(auto link : m_links) {
            delete link;
        }

        for(auto node : m_nodes) {
            delete node;
        }
    }

    Node *NodeSpace::AddNode(Type *type) {
        auto node = NodeRegistry::Create(type);
        if(node != nullptr) {
            m_nodes.push_back(node);
        }

        return node;
    }

    void NodeSpace::RemoveNode(Node *node) {
        auto position = std::find(m_nodes.begin(), m_nodes.end(), node);
        if(position == m_nodes.end()) {
            return;
        }

        //TODO: remove all links associated with this node;

        m_nodes.erase(position);

        delete node;
    }

    //TODO: AddLink, RemoveLink, Evaluate
    //TODO: Add PortData implementations
    //TODO: Add Node Implementations
    //TODO: How to render?
}