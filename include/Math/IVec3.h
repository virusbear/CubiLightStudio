//
// Created by Virusbear on 29.01.2022.
//

#ifndef CUBILIGHTSTUDIO_IVEC3_H
#define CUBILIGHTSTUDIO_IVEC3_H

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

#endif //CUBILIGHTSTUDIO_IVEC3_H
