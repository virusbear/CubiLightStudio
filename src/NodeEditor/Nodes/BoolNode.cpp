//
// Created by Virusbear on 28.01.2022.
//

#include "NodeEditor/Nodes/BoolNode.h"

namespace CubiLight {
    BoolNode::BoolNode(const std::string name, int id): Node(name, id),
        m_input(ConfigPort<Input, BoolPortData>("Input")),
        m_output(ConfigPort<Output, BoolPortData>("Output")) {}

    Node *BoolNode::Create(const std::string name, int id) {
        return new BoolNode(name, id);
    }

    void BoolNode::Evaluate() {
        m_input.PullData();

        m_output.value = m_input.value;
    }
}
