//
// Created by Virusbear on 29.01.2022.
//

#include "Math/Color.h"

namespace CubiLight {
    const Color Color::Black = Color();
    const Color Color::White = Color(1.0f, 1.0f, 1.0f, 1.0f);
    const Color Color::Transparent = Color(0.0f, 0.0f, 0.0f, 0.0f);

    Color::Color() noexcept {
        r = g = b = 0.0f;
        a = 1.0f;
    }

    Color::Color(float _r, float _g, float _b, float _a) noexcept {
        r = _r;
        g = _g;
        b = _b;
        a = _a;
    }

    Color::Color(int _r, int _g, int _b, int _a) noexcept {
        r = (float)_r / 255.0f;
        g = (float)_g / 255.0f;
        b = (float)_b / 255.0f;
        a = (float)_a / 255.0f;
    }

    unsigned int Color::ToInt(ColorFormat format) {
        switch (format) {
            case ColorFormat_ARGB:
                return ICOLOR(a, r, g, b);
            case ColorFormat_ABGR:
                return ICOLOR(a, b, g, r);
            case ColorFormat_RGBA:
                return ICOLOR(r, g, b, a);
            case ColorFormat_RGB:
                return ICOLOR(0, r, g, b);
            case ColorFormat_BGR:
                return ICOLOR(0, b, g, r);
            case ColorFormat_R:
                return ICOLOR(0, 0, 0, r);
            default:
                return 0;
        }
    }
}