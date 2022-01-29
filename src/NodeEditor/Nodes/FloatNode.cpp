//
// Created by Virusbear on 29.01.2022.
//

#include "NodeEditor/Nodes/FloatNode.h"

namespace CubiLight {
    FloatNode::FloatNode(const std::string name, int id): Node(name, id),
        m_input(ConfigPort<Input, FloatPortData>("Input")),
        m_output(ConfigPort<Output, FloatPortData>("Output")) {

        m_output.min = 0;
        m_output.max = 100;
    }

    void FloatNode::SetMin(float min) {
        m_output.min = min;
    }

    void FloatNode::SetMax(float max) {
        m_output.max = max;
    }

    Node *FloatNode::Create(const std::string name, int id) {
        return new FloatNode(name, id);
    }

    void FloatNode::Evaluate() {
        m_input.PullData();

        m_output.value = m_input.value;
    }
}