//
// Created by Virusbear on 29.01.2022.
//

#ifndef CUBILIGHTSTUDIO_INTPORTDATA_H
#define CUBILIGHTSTUDIO_INTPORTDATA_H

#include "NodeEditor/PortData.h"

namespace CubiLight {
    struct IntPortData: public PortData {
        IntPortData(): value(false) {}
        int value;
        int min;
        int max;

        void Render() override;
    };
}

#endif //CUBILIGHTSTUDIO_INTPORTDATA_H
