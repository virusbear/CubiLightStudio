//
// Created by Virusbear on 29.01.2022.
//

#include "IVec3.h"
#include <cstdint>

namespace CubiLight {
    const IVec3 IVec3::Zero = IVec3();

    IVec3::IVec3() {
        x = y = z = 0;
    }

    IVec3::IVec3(int32_t _x, int32_t _y, int32_t _z) {
        x = _x;
        y = _y;
        z = _z;
    }

    Vec3 IVec3::ToVec3() {
        return Vec3((float)x, (float)y, (float)z);
    }
}