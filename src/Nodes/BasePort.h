//
// Created by faf on 28.06.2022.
//

#ifndef CUBILIGHTSTUDIO_BASEPORT_H
#define CUBILIGHTSTUDIO_BASEPORT_H

#include "Port.h"
#include "../Math/IVec2.h"

namespace CubiLight {
    template <typename T>
    class BasePort: public Port {
    protected:
        T *mData;
        //TODO: Is this ok?
        T mDefault;
    public:
        BasePort(std::string& name, PortDirection dir, Node& node, T defaultValue): Port(name, dir, node), mDefault(defaultValue) {}
        void SetData(T value);
        void LinkFrom(Port &other) override;
        void Unlink() override;
        const T& GetData();
    };
}

#endif //CUBILIGHTSTUDIO_BASEPORT_H
