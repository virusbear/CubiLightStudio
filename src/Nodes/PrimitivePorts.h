//
// Created by Virusbear on 01.07.2022.
//

#ifndef CUBILIGHTSTUDIO_PRIMITIVEPORTS_H
#define CUBILIGHTSTUDIO_PRIMITIVEPORTS_H

#include "BasePort.h"

namespace CubiLight {
    //TODO: Optimize port definition as this is kind of repetitive

    class BoolPort: BasePort<bool> {
        BoolPort(std::string& name, PortDirection dir, Node& node): BasePort<bool>(name, dir, node) {
            SetDefault(false);
        }
    };

    class UBytePort: BasePort<uint8_t> {
        UBytePort(std::string& name, PortDirection dir, Node& node): BasePort<uint8_t>(name, dir, node) {
            SetDefault(0);
        }
    };

    class UShortPort: BasePort<uint16_t> {
        UShortPort(std::string& name, PortDirection dir, Node& node): BasePort<uint16_t>(name, dir, node) {
            SetDefault(0);
        }
    };

    class UIntPort: BasePort<uint32_t> {
        UIntPort(std::string& name, PortDirection dir, Node& node): BasePort<uint32_t>(name, dir, node) {
            SetDefault(0);
        }
    };

    class ULongPort: BasePort<uint64_t> {
        ULongPort(std::string& name, PortDirection dir, Node& node): BasePort<uint64_t>(name, dir, node) {
            SetDefault(0);
        }
    };

    class BytePort: BasePort<int8_t> {
        BytePort(std::string& name, PortDirection dir, Node& node): BasePort<int8_t>(name, dir, node) {
            SetDefault(0);
        }
    };

    class ShortPort: BasePort<int16_t> {
        ShortPort(std::string& name, PortDirection dir, Node& node): BasePort<int16_t>(name, dir, node) {
            SetDefault(0);
        }
    };

    class IntPort: BasePort<int32_t> {
        IntPort(std::string& name, PortDirection dir, Node& node): BasePort<int32_t>(name, dir, node) {
            SetDefault(0);
        }
    };

    class LongPort: BasePort<int64_t> {
        LongPort(std::string& name, PortDirection dir, Node& node): BasePort<int64_t>(name, dir, node) {
            SetDefault(0);
        }
    };

    class FloatPort: BasePort<float> {
        FloatPort(std::string& name, PortDirection dir, Node& node): BasePort<float>(name, dir, node) {
            SetDefault(0.0f);
        }
    };

    class DoublePort: BasePort<double> {
        DoublePort(std::string& name, PortDirection dir, Node& node): BasePort<double>(name, dir, node) {
            SetDefault(0.0f);
        }
    };
}

#endif //CUBILIGHTSTUDIO_PRIMITIVEPORTS_H
