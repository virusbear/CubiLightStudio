//
// Created by Virusbear on 29.01.2022.
//

#ifndef CUBILIGHTSTUDIO_IVEC2_H
#define CUBILIGHTSTUDIO_IVEC2_H

#include "IVec3.h"
#include "Vec2.h"

namespace CubiLight {
    struct IVec2 {
        IVec2() noexcept;

        IVec2(int _x, int _y);

        IVec3 XY0();
        Vec2 ToVec2();

        int x;
        int y;

        static const IVec2 Zero;
    };
}

#endif //CUBILIGHTSTUDIO_IVEC2_H
