//
// Created by faf on 28.06.2022.
//

#ifndef CUBILIGHTSTUDIO_BASEPORT_H
#define CUBILIGHTSTUDIO_BASEPORT_H

#include "Port.h"

namespace CubiLight {
    template <typename T>
    class BasePort: Port {
    protected:
        T *data;
        //TODO: Is this ok?
        //TODO: this assumes that setDefault will always be called before a port is used
        T defaultValue = NULL;
    public:
        BasePort(std::string& name, PortDirection dir, Node& node): Port(name, dir, node) {}
        void SetDefault(T& value);
        void LinkFrom(Port &other) override;
        void Unlink() override;
        T& GetData();
    };
}

#endif //CUBILIGHTSTUDIO_BASEPORT_H
