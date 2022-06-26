#pragma once

#include "Node.h"
#include <vector>
#include "Port.h"

namespace CubiLight
{
    class AbstractNode: Node {
    private:
        AbstractNode();
        std::string& mName;
        std::vector<Port *> mPorts;

        template <class T>
        Port *CreatePort(std::string& name, PortDirection dir) {
            auto port = new T(name, dir, *this);
            mPorts.push_back(port);
            return port;
        }
    public:
        AbstractNode(std::string& name): mName(name) {}
        std::vector<Port *> GetPorts() const { return mPorts; };
    protected:
        template<class Port>
        Port *Input(std::string& name) {
            return CreatePort<Port>(name, PortDirection::Input);
        }

        template<class Port>
        Port *Output(std::string& name) {
            return CreatePort<Port>(name, PortDirection::Output);
        }
    };
}
