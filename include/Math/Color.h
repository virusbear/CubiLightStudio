//
// Created by Virusbear on 29.01.2022.
//

#ifndef CUBILIGHTSTUDIO_COLOR_H
#define CUBILIGHTSTUDIO_COLOR_H

#include <algorithm>

namespace CubiLight {
    #define ICOLOR(A,B,C,D) std::clamp((int)((A) * 255), 0, 255) << 24 | std::clamp((int)((B) * 255), 0, 255) << 16 | std::clamp((int)((C) * 255), 0, 255) << 8 | std::clamp((int)((D) * 255), 0, 255)

    enum ColorFormat {
        ColorFormat_ARGB,
        ColorFormat_ABGR,
        ColorFormat_RGBA,
        ColorFormat_RGB,
        ColorFormat_BGR,
        ColorFormat_R
    };

    struct Color {
        Color() noexcept;
        Color(float _r, float _g, float _b, float _a) noexcept;
        Color(int _r, int _g, int _b, int _a) noexcept;

        unsigned int ToInt(ColorFormat format);

        float r;
        float g;
        float b;
        float a;

        static const Color Black;
        static const Color White;
        static const Color Transparent;
    };
}

#endif //CUBILIGHTSTUDIO_COLOR_H
