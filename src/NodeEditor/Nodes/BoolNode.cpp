//
// Created by Virusbear on 31.01.2022.
//

#include "NodeEditor/Nodes/BoolNode.h"
#include "NodeEditor/PortData/BoolPortData.h"

namespace CubiLight {
    BoolNode::BoolNode(Type *type, const std::string name): Node(type, name),
        m_input(ConfigPort<Input, BoolPortData>("Input")),
        m_output(ConfigPort<Output, BoolPortData>("Output")) {}

    void BoolNode::Evaluate() {
        m_output.Value = m_input.Value;
    }

    Node *BoolNode::Create(Type *type, const std::string name) {
        return new BoolNode(type, name);
    }
}

