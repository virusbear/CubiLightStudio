//
// Created by Virusbear on 27.01.2022.
//

#ifndef CUBILIGHTSTUDIO_NODE_H
#define CUBILIGHTSTUDIO_NODE_H

#include <vector>
#include <string>
#include "Port.h"
#include "NodeEditor/IdStorage.h"

namespace CubiLight {
    class Node {
    public:
        Node(const std::string name, int id);
        virtual ~Node();
        void Update();
        virtual void Evaluate() = 0;
        int GetId() const { return m_id; };
    protected:
        template<PortDirection Dir, typename Type>
        Type& ConfigPort(const std::string name) {
            auto port = new Port(IdStorage::NewPortId(), Dir, new Type(), name);

            m_ports.push_back(port);

            return (Type& )port->GetData();
        }
    private:
        const std::string m_name;
        int m_id;
        std::vector<Port *> m_ports;
    };
}

#endif //CUBILIGHTSTUDIO_NODE_H
