//
// Created by Virusbear on 31.01.2022.
//

#ifndef CUBILIGHTSTUDIO_BOOLNODE_H
#define CUBILIGHTSTUDIO_BOOLNODE_H

#include "NodeEditor/Node.h"
#include "NodeEditor/PortData/BoolPortData.h"

namespace CubiLight {
    class BoolNode: public Node {
    public:
        BoolNode(Type *type, const std::string name);
        void Evaluate() override;
        static Node *Create(Type *type, const std::string name);
    private:
        BoolPortData& m_input;
        BoolPortData& m_output;
    };
}

#endif //CUBILIGHTSTUDIO_BOOLNODE_H
