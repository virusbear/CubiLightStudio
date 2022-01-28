//
// Created by Virusbear on 28.01.2022.
//

#ifndef CUBILIGHTSTUDIO_NODEREGISTRY_H
#define CUBILIGHTSTUDIO_NODEREGISTRY_H

#include <map>
#include <vector>
#include <string>

#include "NodeEditor/Node.h"
#include "NodeEditor/IdStorage.h"

namespace CubiLight {
    typedef Node *(*NodeFactory)(const std::string name, int id);

    class NodeRegistry {
    public:
        static void Register(const std::string name, NodeFactory factory) {
            m_definitions[name] = factory;
        }
        static Node *Create(const std::string name) {
            if(m_definitions.find(name) == m_definitions.end()) {
                return nullptr;
            }

            auto factory = m_definitions[name];
            return factory(name, IdStorage::NewNodeId());
        }

        static std::vector<std::string> RegisteredNodes() {
            std::vector<std::string> keys;
            for(auto definition : m_definitions) {
                keys.push_back(definition.first);
            }

            return keys;
        }
    private:
        static std::map<std::string, NodeFactory> m_definitions;
    };
}

#endif //CUBILIGHTSTUDIO_NODEREGISTRY_H
