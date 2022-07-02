//
// Created by Virusbear on 01.07.2022.
//

#ifndef CUBILIGHTSTUDIO_PRIMITIVEPORTS_H
#define CUBILIGHTSTUDIO_PRIMITIVEPORTS_H

#include "BasePort.h"

namespace CubiLight {
    //TODO: Optimize port definition as this is kind of repetitive

    struct VoidPort: public BasePort<void *> {
        VoidPort(std::string& name, PortDirection dir, Node& node): BasePort<void *>(name, dir, node, nullptr) {}
    };

    struct BoolPort: public BasePort<bool> {
        BoolPort(std::string& name, PortDirection dir, Node& node): BasePort<bool>(name, dir, node, false) {}
    };

    struct UBytePort: public BasePort<uint8_t> {
        UBytePort(std::string& name, PortDirection dir, Node& node): BasePort<uint8_t>(name, dir, node, 0) {}
    };

    struct UShortPort: public BasePort<uint16_t> {
        UShortPort(std::string& name, PortDirection dir, Node& node): BasePort<uint16_t>(name, dir, node, 0) {}
    };

    struct UIntPort: public BasePort<uint32_t> {
        UIntPort(std::string& name, PortDirection dir, Node& node): BasePort<uint32_t>(name, dir, node, 0) {}
    };

    struct ULongPort: public BasePort<uint64_t> {
        ULongPort(std::string& name, PortDirection dir, Node& node): BasePort<uint64_t>(name, dir, node, 0) {}
    };

    struct BytePort: public BasePort<int8_t> {
        BytePort(std::string& name, PortDirection dir, Node& node): BasePort<int8_t>(name, dir, node, 0) {}
    };

    struct ShortPort: public BasePort<int16_t> {
        ShortPort(std::string& name, PortDirection dir, Node& node): BasePort<int16_t>(name, dir, node, 0) {}
    };

    struct IntPort: public BasePort<int32_t> {
        IntPort(std::string& name, PortDirection dir, Node& node): BasePort<int32_t>(name, dir, node, 0) {}
    };

    struct LongPort: public BasePort<int64_t> {
        LongPort(std::string& name, PortDirection dir, Node& node): BasePort<int64_t>(name, dir, node, 0) {}
    };

    struct FloatPort: public BasePort<float> {
        FloatPort(std::string& name, PortDirection dir, Node& node): BasePort<float>(name, dir, node, 0.0f) {}
    };

    struct DoublePort: public BasePort<double> {
        DoublePort(std::string& name, PortDirection dir, Node& node): BasePort<double>(name, dir, node, 0.0) {}
    };

    struct StringPort: public BasePort<std::string> {
        StringPort(std::string& name, PortDirection dir, Node& node): BasePort<std::string>(name, dir, node, "") {}
    };
}

#endif //CUBILIGHTSTUDIO_PRIMITIVEPORTS_H
