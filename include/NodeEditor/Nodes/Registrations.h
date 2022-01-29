//
// Created by Virusbear on 29.01.2022.
//

#ifndef CUBILIGHTSTUDIO_REGISTRATIONS_H
#define CUBILIGHTSTUDIO_REGISTRATIONS_H

#include "NodeEditor/NodeRegistry.h"
#include "NodeEditor/Nodes/BoolNode.h"
#include "NodeEditor/Nodes/IntNode.h"
#include "NodeEditor/Nodes/FloatNode.h"
#include "NodeEditor/Nodes/ComposeIVec2Node.h"
#include "NodeEditor/Nodes/ComposeIVec3Node.h"

namespace CubiLight {
    static void RegisterNodes() {
        NodeRegistry::Register("Boolean", BoolNode::Create);
        NodeRegistry::Register("Integer", IntNode::Create);
        NodeRegistry::Register("Float", FloatNode::Create);
        NodeRegistry::Register("IVec2", ComposeIVec2Node::Create);
        NodeRegistry::Register("IVec3", ComposeIVec3Node::Create);
    }
}

#endif //CUBILIGHTSTUDIO_REGISTRATIONS_H
