#pragma once

#include "Vec3.h"

namespace CubiLight {
    struct IVec3 {
        IVec3();

        IVec3(int _x, int _y, int _z);

        Vec3 ToVec3();

        int x;
        int y;
        int z;

        static const IVec3 Zero;
    };
}
