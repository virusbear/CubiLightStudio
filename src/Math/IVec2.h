#pragma once

#include "IVec3.h"
#include "Vec2.h"
#include <cstdint>

namespace CubiLight {
    struct IVec2 {
        IVec2() noexcept;

        IVec2(int32_t _x, int32_t _y);

        IVec3 XY0();
        Vec2 ToVec2();

        int32_t x;
        int32_t y;

        static const IVec2 Zero;
    };
}