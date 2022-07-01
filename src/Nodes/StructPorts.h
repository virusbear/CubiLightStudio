//
// Created by Virusbear on 01.07.2022.
//

#ifndef CUBILIGHTSTUDIO_STRUCTPORTS_H
#define CUBILIGHTSTUDIO_STRUCTPORTS_H

#include "BasePort.h"
#include "../Math/Color.h"
#include "../Math/IVec2.h"
#include "../Math/IVec3.h"
#include "../Math/Vec2.h"
#include "../Math/Vec3.h"

namespace CubiLight {
    class ColorPort: BasePort<Color> {
        ColorPort(std::string& name, PortDirection dir, Node& node): BasePort<Color>(name, dir, node) {
            SetDefault(Color::Transparent);
        }
    };

    class IVec2Port: BasePort<IVec2> {
        IVec2Port(std::string& name, PortDirection dir, Node& node): BasePort<IVec2>(name, dir, node) {
            SetDefault(IVec2::Zero);
        }
    };

    class IVec3Port: BasePort<IVec3> {
        IVec3Port(std::string& name, PortDirection dir, Node& node): BasePort<IVec3>(name, dir, node) {
            SetDefault(IVec3::Zero);
        }
    };

    class Vec2Port: BasePort<Vec2> {
        Vec2Port(std::string& name, PortDirection dir, Node& node): BasePort<Vec2>(name, dir, node) {
            SetDefault(Vec2::Zero);
        }
    };

    class Vec3Port: BasePort<Vec3> {
        Vec3Port(std::string& name, PortDirection dir, Node& node): BasePort<Vec3>(name, dir, node) {
            SetDefault(Vec3::Zero);
        }
    };
}

#endif //CUBILIGHTSTUDIO_STRUCTPORTS_H
