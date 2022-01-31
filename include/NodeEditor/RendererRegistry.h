//
// Created by Virusbear on 31.01.2022.
//

#ifndef CUBILIGHTSTUDIO_RENDERERREGISTRY_H
#define CUBILIGHTSTUDIO_RENDERERREGISTRY_H

#include <string>
#include "Type.h"
#include "PortRenderer.h"
#include <unordered_map>

namespace CubiLight {
    class RendererRegistry {
    public:
        static void Register(Type *type, PortRenderer *renderer) noexcept;
        static PortRenderer *Get(Type *type);
    private:
        static std::unordered_map<Type *, PortRenderer *> m_registrations;
    };
}

#endif //CUBILIGHTSTUDIO_RENDERERREGISTRY_H
