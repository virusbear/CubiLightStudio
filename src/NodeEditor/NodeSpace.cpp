//
// Created by Virusbear on 29.01.2022.
//

#include "NodeEditor/NodeSpace.h"
#include "NodeEditor/NodeRegistry.h"
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

        //TODO: Optimize
        for(auto port : node->GetPorts()) {
            for(auto link : m_links) {
                if(port->GetDirection() == PortDirection::Input) {
                    if(&(link->end) == port) {
                        RemoveLink(link);
                    }
                } else {
                    if(&(link->start) == port) {
                        RemoveLink(link);
                    }
                }
            }
        }

        m_nodes.erase(position);

        delete node;
    }

    Link *NodeSpace::AddLink(Port *start, Port *end) {
        if(start->GetType() != end->GetType()) {
            return nullptr;
        }

        Link *link;
        if(start->GetDirection() == Input) {
            link = new Link(*end, *start);
        } else {
            link = new Link(*start, *end);
        }

        m_links.push_back(link);
        return link;
    }

    void NodeSpace::RemoveLink(Link *link) {
        auto position = std::find(m_links.begin(), m_links.end(), link);
        if(position == m_links.end()) {
            return;
        }

        m_links.erase(position);

        delete link;
    }

    //TODO: Add PortData implementations
    //TODO: Add Node Implementations
    //TODO: How to render?
}