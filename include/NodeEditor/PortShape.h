//
// Created by Virusbear on 31.01.2022.
//

#ifndef CUBILIGHTSTUDIO_PORTSHAPE_H
#define CUBILIGHTSTUDIO_PORTSHAPE_H

#include "imnodes.h"

namespace CubiLight {
    enum PortShape {
        Circle = ImNodesPinShape_Circle,
        CircleFilled = ImNodesPinShape_CircleFilled,
        Triangle = ImNodesPinShape_Triangle,
        TriangleFilled = ImNodesPinShape_TriangleFilled,
        Quad = ImNodesPinShape_Quad,
        QuadFilled = ImNodesPinShape_QuadFilled
    };
}

#endif //CUBILIGHTSTUDIO_PORTSHAPE_H
