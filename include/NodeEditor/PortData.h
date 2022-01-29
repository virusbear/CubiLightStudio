//
// Created by Virusbear on 28.01.2022.
//

#ifndef CUBILIGHTSTUDIO_PORTDATA_H
#define CUBILIGHTSTUDIO_PORTDATA_H

#include <imgui.h>
#include "Math/Color.h"
#include <imnodes.h>

namespace CubiLight {
    enum PortShape {
        Circle = ImNodesPinShape_Circle,
        CircleFilled = ImNodesPinShape_CircleFilled,
        Quad = ImNodesPinShape_Quad,
        QuadFilled = ImNodesPinShape_QuadFilled,
        Triangle = ImNodesPinShape_Triangle,
        TriangleFilled = ImNodesPinShape_TriangleFilled
    };

    class PortData {
    public:
        virtual ~PortData() = default;
        virtual void Render() = 0;
        virtual std::string GetType() = 0;
        virtual Color GetPortColor() = 0;
        virtual PortShape GetPortShape() = 0;
    };
}

#endif //CUBILIGHTSTUDIO_PORTDATA_H
