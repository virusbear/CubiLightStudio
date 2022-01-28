//
// Created by Virusbear on 28.01.2022.
//

#include "NodeEditor/Nodes/BoolNode.h"

namespace CubiLight {
    static_block {
        NodeRegistry::Register("Boolean", BoolNode::Create);
    }
}
