//
// Created by Virusbear on 29.01.2022.
//

#include "NodeEditor/Nodes/IntNode.h"

namespace CubiLight {
    IntNode::IntNode(const std::string name, int id): Node(name, id),
        m_input(ConfigPort<Input, IntPortData>("Input")),
        m_output(ConfigPort<Output, IntPortData>("Output")) {

        m_input.min = 0;
        m_input.max = 100;
    }

    void IntNode::SetMin(int min) {
        m_input.min = min;
    }

    void IntNode::SetMax(int max) {
        m_input.max = max;
    }

    Node *IntNode::Create(const std::string name, int id) {
        return new IntNode(name, id);
    }

    void IntNode::Evaluate() {
        m_input.PullData();

        m_output.value = m_input.value;
    }
}