//
// Created by Virusbear on 29.01.2022.
//

#ifndef CUBILIGHTSTUDIO_FLOATNODE_H
#define CUBILIGHTSTUDIO_FLOATNODE_H

#include "NodeEditor/Node.h"
#include "NodeEditor/PortData/FloatPortData.h"

namespace CubiLight {
    class FloatNode: public Node {
    public:
        FloatNode(const std::string name, int id);
        void Evaluate() override;
        static Node *Create(const std::string name, int id);

        void SetMin(float min);
        void SetMax(float max);
    private:
        FloatPortData& m_input;
        FloatPortData& m_output;
    };
}

#endif //CUBILIGHTSTUDIO_FLOATNODE_H
