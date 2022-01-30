//
// Created by Virusbear on 29.01.2022.
//

#ifndef CUBILIGHTSTUDIO_NODEREGISTRY_H
#define CUBILIGHTSTUDIO_NODEREGISTRY_H

#include <string>
#include "Node.h"
#include "Type.h"
#include <unordered_map>

namespace CubiLight {
    typedef Node *(*NodeFactory)(const std::string name);

    class NodeRegistry {
    public:
        static void Register(Type *type, NodeFactory factory) noexcept;
        static Node *Create(Type *type);
    private:
        static std::unordered_map<Type *, NodeFactory> m_registrations;
    };
}

#endif //CUBILIGHTSTUDIO_NODEREGISTRY_H
