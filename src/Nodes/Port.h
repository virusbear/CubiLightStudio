//
// Created by Virusbear on 25.06.2022.
//

#ifndef CUBILIGHTSTUDIO_PORT_H
#define CUBILIGHTSTUDIO_PORT_H

#include <string>
#include "Node.h"

namespace CubiLight {
    class Node;

    enum PortDirection {
        Input,
        Output
    };

    class Port {
    private:
        std::string& mName;
        PortDirection mDir;
        Node& mNode;
    public:
        Port(std::string& name, PortDirection dir, Node& node): mName(name), mDir(dir), mNode(node) {}

        virtual void LinkFrom(Port& other) = 0;
        virtual void Unlink() = 0;

        std::string& GetName() const { return mName; };
        PortDirection GetDir() const { return mDir; };
        Node& GetNode() const { return mNode; };
    };
}

#endif //CUBILIGHTSTUDIO_PORT_H
