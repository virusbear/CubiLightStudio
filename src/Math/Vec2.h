#pragma once

namespace CubiLight {
    struct Vec2 {
        Vec2();

        Vec2(float _x, float _y);

        float x;
        float y;

        static const Vec2 Zero;
    };
}
