//
// Created by Virusbear on 31.01.2022.
//

#ifndef CUBILIGHTSTUDIO_NODEREGISTRATIONS_H
#define CUBILIGHTSTUDIO_NODEREGISTRATIONS_H

#include "NodeEditor/NodeRegistry.h"
#include "NodeEditor/Nodes/BoolNode.h"

namespace CubiLight {
    Type *Constants = new Type(nullptr, "Constants");

    Type *BooleanNode = new Type(Constants, "Boolean");

    void RegisterNodes() {
        NodeRegistry::Register(BooleanNode, BoolNode::Create);
    }
}

#endif //CUBILIGHTSTUDIO_NODEREGISTRATIONS_H
