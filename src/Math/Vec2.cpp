//
// Created by Virusbear on 29.01.2022.
//

#include "Math/Vec2.h"

namespace CubiLight {
    Vec2::Vec2() {
        x = y = 0.0f;
    }

    Vec2::Vec2(float _x, float _y) {
        x = _x;
        y = _y;
    }
}