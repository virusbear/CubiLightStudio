//
// Created by Virusbear on 29.01.2022.
//

#ifndef CUBILIGHTSTUDIO_INTNODE_H
#define CUBILIGHTSTUDIO_INTNODE_H

#include "NodeEditor/Node.h"
#include "NodeEditor/PortData/IntPortData.h"

namespace CubiLight {
    class IntNode: public Node {
    public:
        IntNode(const std::string name, int id);
        void Evaluate() override {}
        static Node *Create(const std::string name, int id);

        void SetMin(int min);
        void SetMax(int max);
    private:
        IntPortData& m_output;
    };
}

#endif //CUBILIGHTSTUDIO_INTNODE_H
