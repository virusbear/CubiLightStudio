//
// Created by Virusbear on 28.01.2022.
//

#ifndef CUBILIGHTSTUDIO_PORTDATA_H
#define CUBILIGHTSTUDIO_PORTDATA_H

#include "imgui.h"

namespace CubiLight {
    class PortData {
    public:
        virtual ~PortData() = default;
        virtual void Render() = 0;
    public:
        bool show = true;
    };
}

#endif //CUBILIGHTSTUDIO_PORTDATA_H
