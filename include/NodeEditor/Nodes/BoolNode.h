//
// Created by Virusbear on 28.01.2022.
//

#ifndef CUBILIGHTSTUDIO_BOOLNODE_H
#define CUBILIGHTSTUDIO_BOOLNODE_H

#include "StaticBlock.h"
#include "NodeEditor/NodeRegistry.h"
#include "NodeEditor/Node.h"
#include <imgui.h>
#include "NodeEditor/PortData.h"

namespace CubiLight {
    class BoolNode: public Node {
    public:
        BoolNode(const std::string name, int id): Node(name, id) {
            m_output = ConfigPort<PortDirection::Output, BoolPortData>("Output");
        }

        void Evaluate() override {}

        static Node *Create(const std::string name, int id) {
            return new BoolNode(name, id);
        }
    private:
        BoolPortData m_output;
    };
}

#endif //CUBILIGHTSTUDIO_BOOLNODE_H
