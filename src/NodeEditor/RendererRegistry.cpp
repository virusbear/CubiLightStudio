//
// Created by Virusbear on 31.01.2022.
//

#include "NodeEditor/RendererRegistry.h"
#include <unordered_map>
#include <cassert>

namespace CubiLight {
    std::unordered_map<Type *, PortRenderer *> RendererRegistry::m_registrations;

    void RendererRegistry::Register(Type *type, PortRenderer *renderer) noexcept {
        assert(m_registrations.find(type) == m_registrations.end());

        m_registrations[type] = renderer;
    }

    PortRenderer *RendererRegistry::Get(Type *type) {
        if(m_registrations.find(type) == m_registrations.end()) {
            return nullptr;
        }

        return m_registrations[type];
    }
}