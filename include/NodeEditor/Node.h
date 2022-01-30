//
// Created by Virusbear on 29.01.2022.
//

#ifndef CUBILIGHTSTUDIO_NODE_H
#define CUBILIGHTSTUDIO_NODE_H

#include <vector>
#include <string>
#include "Port.h"
#include "PortData.h"

namespace CubiLight {
    class Node {
    public:
        explicit Node(Type *type, const std::string name);
        virtual ~Node();
        virtual void Evaluate() = 0;
        std::vector<Port *> GetPorts() const { return m_ports; }
        virtual Type *GetType() = 0;

    protected:
        template<PortDirection Dir, class T>
        T& ConfigPort(const std::string name) {
            auto port = new Port(Dir, name, new T());

            m_ports.push_back(port);

            return port->GetData();
        }

    private:
        const std::string m_name;
        std::vector<Port *> m_ports;
        Type *m_type;
    };
}

#endif //CUBILIGHTSTUDIO_NODE_H
