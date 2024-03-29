//
// Created by Virusbear on 29.01.2022.
//

#include "Vec2.h"

namespace CubiLight {
    const Vec2 Vec2::Zero = Vec2();

    Vec2::Vec2() {
        x = y = 0.0f;
    }

    Vec2::Vec2(float _x, float _y) {
        x = _x;
        y = _y;
    }
}