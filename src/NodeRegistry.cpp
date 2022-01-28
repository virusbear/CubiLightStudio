//
// Created by Virusbear on 28.01.2022.
//

#include "NodeEditor/NodeRegistry.h"

namespace CubiLight {
    std::map<std::string, NodeFactory> NodeRegistry::m_definitions;
}