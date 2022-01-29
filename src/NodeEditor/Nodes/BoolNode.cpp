//
// Created by Virusbear on 28.01.2022.
//

#include "NodeEditor/Nodes/BoolNode.h"

namespace CubiLight {
    static_block {
        NodeRegistry::Register("Boolean", BoolNode::Create);
    }

    BoolNode::BoolNode(const std::string name, int id): Node(name, id),
        m_output(ConfigPort<PortDirection::Output, BoolPortData>("Output")) {}

    Node *BoolNode::Create(const std::string name, int id) {
        return new BoolNode(name, id);
    }
}
