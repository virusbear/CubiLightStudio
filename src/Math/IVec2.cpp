//
// Created by Virusbear on 29.01.2022.
//

#include "Math/IVec2.h"

namespace CubiLight {
    const IVec2 IVec2::Zero = IVec2();

    IVec2::IVec2() noexcept {
        x = y = 0;
    }

    IVec2::IVec2(int _x, int _y) {
        x = _x;
        y = _y;
    }

    IVec3 IVec2::XY0() {
        return IVec3(x, y, 0);
    }

    Vec2 IVec2::ToVec2() {
        return Vec2((float)x, (float)y);
    }
}