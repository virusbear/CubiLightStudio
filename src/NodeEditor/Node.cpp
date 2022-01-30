//
// Created by Virusbear on 29.01.2022.
//

#include "NodeEditor/Node.h"

namespace CubiLight {
    Node::Node(Type *type, const std::string name): m_type(type), m_name(name) {}

    Node::~Node() {
        for(auto port : m_ports) {
            delete port;
        }
    }
}