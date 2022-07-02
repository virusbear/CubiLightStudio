#pragma once

#include "Node.h"
#include <vector>
#include "Port.h"

namespace CubiLight
{
    class AbstractNode: Node {
    private:
        std::string& mName;
        std::vector<Port *> mPorts;

        //TODO: Is it ok to assume that every port has a constructor like this?
        template <class T>
        T *CreatePort(std::string& name, PortDirection dir) {
            auto port = new T(name, dir, *this);
            mPorts.push_back(port);
            return port;
        }
    public:
        AbstractNode(std::string& name): mName(name) {}
        std::vector<Port *> GetPorts() const { return mPorts; };
        std::string& GetName() const { return mName; };
    protected:
        template<class T>
        T *Input(std::string name) {
            return CreatePort<T>(name, PortDirection::Input);
        }

        template<class T>
        T *Output(std::string name) {
            return CreatePort<T>(name, PortDirection::Output);
        }
    };
}
