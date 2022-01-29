//
// Created by Virusbear on 29.01.2022.
//

#ifndef CUBILIGHTSTUDIO_FLOATPORTDATA_H
#define CUBILIGHTSTUDIO_FLOATPORTDATA_H

#include <string>
#include "NodeEditor/PortData.h"

namespace CubiLight {
    struct FloatPortData: public PortData {
        FloatPortData(): value(false) {}
        float value;
        float min;
        float max;

        void Render() override;
        std::string GetType() override;
        Color GetPortColor() override;
        PortShape GetPortShape() override;
    };
}

#endif //CUBILIGHTSTUDIO_FLOATPORTDATA_H
