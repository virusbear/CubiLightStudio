//
// Created by Virusbear on 29.01.2022.
//

#include "NodeTemp/NodeRegistry.h"
#include <unordered_map>
#include <cassert>

namespace CubiLight {
    std::unordered_map<Type *, NodeFactory> NodeRegistry::m_registrations;

    void NodeRegistry::Register(Type *type, NodeFactory factory) noexcept {
        assert(m_registrations.find(type) == m_registrations.end());

        m_registrations[type] = factory;
    }

    Node *NodeRegistry::Create(Type *type) {
        if(m_registrations.find(type) == m_registrations.end()) {
            return nullptr;
        }

        auto factory = m_registrations[type];
        return factory(type->type);
    }
}