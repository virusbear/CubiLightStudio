//
// Created by Virusbear on 28.01.2022.
//

#include "NodeEditor/IdStorage.h"

namespace CubiLight {
    std::unordered_map<ImNodesContext *, IdPool *> IdStorage::m_storage;
}