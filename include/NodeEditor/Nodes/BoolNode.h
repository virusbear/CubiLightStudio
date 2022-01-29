//
// Created by Virusbear on 28.01.2022.
//

#ifndef CUBILIGHTSTUDIO_BOOLNODE_H
#define CUBILIGHTSTUDIO_BOOLNODE_H

#include "NodeEditor/NodeRegistry.h"
#include "NodeEditor/Node.h"
#include <imgui.h>
#include "NodeEditor/PortData/BoolPortData.h"

namespace CubiLight {
    class BoolNode: public Node {
    public:
        BoolNode(const std::string name, int id);

        void Evaluate() override;

        static Node *Create(const std::string name, int id);
    private:
        BoolPortData& m_output;
        BoolPortData& m_input;
    };
}

#endif //CUBILIGHTSTUDIO_BOOLNODE_H
