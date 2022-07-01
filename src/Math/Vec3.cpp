//
// Created by Virusbear on 29.01.2022.
//

#include "Vec3.h"

namespace CubiLight {
    const Vec3 Vec3::Zero = Vec3();

    Vec3::Vec3() {
        x = y = z = 0.0f;
    }

    Vec3::Vec3(float _x, float _y, float _z) {
        x = _x;
        y = _y;
        z = _z;
    }
}