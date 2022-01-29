//
// Created by Virusbear on 29.01.2022.
//

#ifndef CUBILIGHTSTUDIO_COMPOSEIVEC2NODE_H
#define CUBILIGHTSTUDIO_COMPOSEIVEC2NODE_H

#include "NodeEditor/Node.h"
#include "NodeEditor/PortData/IntPortData.h"
#include "NodeEditor/PortData/IVec2PortData.h"

namespace CubiLight {
    class ComposeIVec2Node: public Node {
    public:
        ComposeIVec2Node(const std::string name, int id);
        void Evaluate() override {}
        static Node *Create(const std::string name, int id);
    private:
        IntPortData& m_x;
        IntPortData& m_y;
        IVec2PortData& m_output;
    };
}

#endif //CUBILIGHTSTUDIO_COMPOSEIVEC2NODE_H
