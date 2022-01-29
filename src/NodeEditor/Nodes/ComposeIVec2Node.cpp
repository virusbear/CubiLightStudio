//
// Created by Virusbear on 29.01.2022.
//

#include "NodeEditor/Nodes/ComposeIVec2Node.h"
#include "StaticBlock.h"
#include "NodeEditor/NodeRegistry.h"

namespace CubiLight {
    static_block {
        NodeRegistry::Register("Compose IVec2", ComposeIVec2Node::Create);
    }

    ComposeIVec2Node::ComposeIVec2Node(const std::string name, int id): Node(name, id),
        m_x(ConfigPort<Input, IntPortData>("X")),
        m_y(ConfigPort<Input, IntPortData>("Y")),
        m_output(ConfigPort<Output, IVec2PortData>("Output")) {

        m_output.show = false;
        m_x.min = 0;
        m_x.max = 100;
        m_y.min = 0;
        m_y.max = 100;
    }

    Node *ComposeIVec2Node::Create(const std::string name, int id) {
        return new ComposeIVec2Node(name, id);
    }
}
