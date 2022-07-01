#pragma once

namespace CubiLight {
    struct Vec3 {
        Vec3();

        Vec3(float _x, float _y, float _z);

        float x;
        float y;
        float z;

        static const Vec3 Zero;
    };
}