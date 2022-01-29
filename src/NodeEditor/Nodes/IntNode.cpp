//
// Created by Virusbear on 29.01.2022.
//

#include "NodeEditor/Nodes/IntNode.h"
#include "NodeEditor/NodeRegistry.h"
#include "StaticBlock.h"

namespace CubiLight {
    static_block {
        NodeRegistry::Register("Integer", IntNode::Create);
    }

    IntNode::IntNode(const std::string name, int id): Node(name, id),
        m_output(ConfigPort<Output, IntPortData>("Output")) {

        m_output.min = 0;
        m_output.max = 100;
    }

    void IntNode::SetMin(int min) {
        m_output.min = min;
    }

    void IntNode::SetMax(int max) {
        m_output.max = max;
    }

    Node *IntNode::Create(const std::string name, int id) {
        return new IntNode(name, id);
    }
}