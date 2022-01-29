//
// Created by Virusbear on 29.01.2022.
//

#ifndef CUBILIGHTSTUDIO_COMPOSEIVEC3NODE_H
#define CUBILIGHTSTUDIO_COMPOSEIVEC3NODE_H

#include "NodeEditor/Node.h"
#include "NodeEditor/PortData/IntPortData.h"
#include "NodeEditor/PortData/IVec3PortData.h"

namespace CubiLight {
    class ComposeIVec3Node: public Node {
    public:
        ComposeIVec3Node(const std::string name, int id);
        void Evaluate() override;
        static Node *Create(const std::string name, int id);
    private:
        IntPortData& m_x;
        IntPortData& m_y;
        IntPortData& m_z;
        IVec3PortData& m_output;
    };
}

#endif //CUBILIGHTSTUDIO_COMPOSEIVEC3NODE_H
