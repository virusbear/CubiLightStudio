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
    struct ColorPort: BasePort<Color> {
        ColorPort(std::string& name, PortDirection dir, Node& node): BasePort<Color>(name, dir, node, Color::Transparent) {}
    };

    struct IVec2Port: BasePort<IVec2> {
        IVec2Port(std::string& name, PortDirection dir, Node& node): BasePort<IVec2>(name, dir, node, IVec2::Zero) {}
    };

    struct IVec3Port: BasePort<IVec3> {
        IVec3Port(std::string& name, PortDirection dir, Node& node): BasePort<IVec3>(name, dir, node, IVec3::Zero) {}
    };

    struct Vec2Port: BasePort<Vec2> {
        Vec2Port(std::string& name, PortDirection dir, Node& node): BasePort<Vec2>(name, dir, node, Vec2::Zero) {}
    };

    struct Vec3Port: BasePort<Vec3> {
        Vec3Port(std::string& name, PortDirection dir, Node& node): BasePort<Vec3>(name, dir, node, Vec3::Zero) {}
    };
}

#endif //CUBILIGHTSTUDIO_STRUCTPORTS_H
