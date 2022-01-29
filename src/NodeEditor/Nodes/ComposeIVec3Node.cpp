//
// Created by Virusbear on 29.01.2022.
//

#include "NodeEditor/Nodes/ComposeIVec3Node.h"

namespace CubiLight {
    ComposeIVec3Node::ComposeIVec3Node(const std::string name, int id) : Node(name, id),
        m_x(ConfigPort<Input, IntPortData>("X")),
        m_y(ConfigPort<Input, IntPortData>("Y")),
        m_z(ConfigPort<Input, IntPortData>("Z")),
        m_output(ConfigPort<Output, IVec3PortData>("Output")) {

        m_x.min = 0;
        m_x.max = 100;
        m_y.min = 0;
        m_y.max = 100;
        m_z.min = 0;
        m_z.max = 100;
    }

    void ComposeIVec3Node::Evaluate() {
        m_x.PullData();
        m_y.PullData();
        m_z.PullData();

        m_output.value = IVec3(m_x.value, m_y.value, m_z.value);
    }

    Node *ComposeIVec3Node::Create(const std::string name, int id) {
        return new ComposeIVec3Node(name, id);
    }
}